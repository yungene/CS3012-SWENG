#pragma once

#include <map>
#include <vector>
#include <stack>

// author: Jevgenijus Cistiakovas cistiakj

// Note: This graph only allows for nodes with unique values.
// TODO(cistiakj): consider allowing nodes to have non-unique values.
//                      This means using some type of key to uniquely identify
//                      nodes.
template <typename T>
class Graph {
 public:
  Graph() = default;
  void addVertex(T const& value);
  void addVertex(T&& value);
  void addEdge(T const& src, T const& dest);
  bool isDag();
  bool isEmpty();
  bool contains(T const& value);
  // Definition as of Bender et al. 2005 "Lowest common ancestors in trees and
  // directed acyclic graphs" An LCA w of nodes u and v in a DAG is an ancestor
  // of both u and v where w has no descendants that are also ancestors of both
  // u and v. Note: assume lca(x,x) = x, i.e. lca is reflexive
  std::vector<T> lca(T const& u, T const& v);

 private:
  class Vertex;

  typename std::map<T, Vertex> vertex_set_;
  static constexpr int kWhite = 0;
  static constexpr int kGrey = 1;
  static constexpr int kBlack = 2;

  bool isDagUtil(T val);

  class Edge {
    friend class Graph;
   public:
    Edge(T src, T dest) : src_(src), dest_(dest), visited_(false){};
    bool operator==(Edge& other) {
      return (src_ == other.src_ && dest_ == other.dest_);
    }

   private:
    T src_;
    T dest_;
    bool visited_;
  };

  class Vertex {
    friend class Graph;
   public:
    Vertex(T const& in) : data_(in), colour_(kWhite){};
    Vertex() = default;
    void addInEdge(Edge e);
    void addOutEdge(Edge e);

   private:
    T data_;
    int colour_;
    std::vector<Edge> out_edges_;
    std::vector<Edge> in_edges_;
  };
};

template <typename T>
inline bool Graph<T>::contains(T const& value) {
  return (vertex_set_.find(value) != vertex_set_.end());
}

template <typename T>
inline void Graph<T>::addVertex(T const& value) {
  if (contains(value)) {
    return;
  }
  Vertex v(value);
  vertex_set_.insert(std::pair<T,Vertex>(value, v));
}

template <typename T>
inline void Graph<T>::addVertex(T&& value) {
  addVertex(value);
}

template <typename T>
inline void Graph<T>::addEdge(T const& src, T const& dest) {
  if (!contains(src) || !contains(dest)) {
    // return for now
    // TODO(cistiakj): document the expected behaviour
    return;
  }
  Edge e(src, dest);
  vertex_set_[src].addOutEdge(e);
  vertex_set_[dest].addInEdge(e);
}

template <typename T>
inline bool Graph<T>::isDag() {
  // mark all vertices unvisited
  for (auto& pair: vertex_set_) {
    pair.second.colour_ = kWhite;
  }
  for (auto& pair : vertex_set_) {
    // do a dfs for each unvisited vertex
    if (pair.second.colour_ == kWhite) {
      if (!isDagUtil(pair.first)) {
        return false;
      }
    }
  }

  return true;
}

// TODO(cistiakj): Consider passing by pointer, as copying for
// arbitrary object can be expensive.
template <typename T>
inline bool Graph<T>::isDagUtil(T val) {
  auto& u = vertex_set_[val];
  u.colour_ = kGrey;

  for (auto& edge : u.out_edges_) {
    // check for back-edge
    auto& v = vertex_set_[edge.dest_];
    if (v.colour_ == kGrey) {
      return false;
    }
    if (v.colour_ == kWhite && !isDagUtil(edge.dest_)) {
      return false;
    }
  }

  u.colour_ = kBlack;
  return true;
}

template <typename T>
inline bool Graph<T>::isEmpty() {
  return vertex_set_.size() == 0;
}

template <typename T>
inline std::vector<T> Graph<T>::lca(T const& u, T const& v) {
  return std::vector<T>();
}


template <typename T>
inline void Graph<T>::Vertex::addInEdge(Edge e) {
  for (auto& ee : in_edges_) {
    if (e == e) {
      // Edge already exists
      return;
    }
  }
  in_edges_.push_back(e);
}

template <typename T>
inline void Graph<T>::Vertex::addOutEdge(Edge e) {
  for (auto& ee : out_edges_) {
    if (e == e) {
      // Edge already exists
      return;
    }
  }
  out_edges_.push_back(e);
}