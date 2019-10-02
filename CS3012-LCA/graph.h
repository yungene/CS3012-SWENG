#pragma once

#include <map>
#include <vector>

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

  typename std::map<T, Vertex> vertex_set;

  class Edge {
   public:
    Edge(Graph<T>* const ref, T src, T dest) : visited_(false) {
      src_ = &(ref->vertex_set[src]);
      src_ = &ref->vertex_set[dest];
    };
    Edge(Vertex* src, Vertex* dest) : src_(src), dest_(dest), visited_(false){};
    bool operator==(Edge& other) {
      return (src_ == other.src_ && dest_ == other.dest_ &&
              visited_ == other.visited_);
    }

   private:
    Vertex* src_;
    Vertex* dest_;
    bool visited_;
  };

  class Vertex {
   public:
    Vertex(T const& in) : data(in), colour(0){};
    Vertex() = default;
    void addInEdge(Edge e);
    void addOutEdge(Edge e);

   private:
    T data;
    int colour;
    std::vector<Edge> out_edges;
    std::vector<Edge> in_edges;
  };
};

template <typename T>
inline bool Graph<T>::contains(T const& value) {
  return (vertex_set.find(value) != vertex_set.end());
}

template <typename T>
inline void Graph<T>::addVertex(T const& value) {
  if (contains(value)) {
    return;
  }
  Vertex v(value);
  vertex_set.insert(std::pair<T,Vertex>(value, v));
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
  Edge e(this, src, dest);
  vertex_set[src].addOutEdge(e);
  vertex_set[dest].addInEdge(e);
}

template <typename T>
inline bool Graph<T>::isDag() {
  return false;
}

template <typename T>
inline bool Graph<T>::isEmpty() {
  return vertex_set.size() == 0;
}

template <typename T>
inline std::vector<T> Graph<T>::lca(T const& u, T const& v) {
  return std::vector<T>();
}

template <typename T>
inline void Graph<T>::Vertex::addInEdge(Edge e) {
  for (auto& ee : in_edges) {
    if (e == e) {
      // Edge already exists
      return;
    }
  }
  in_edges.push_back(e);
}

template <typename T>
inline void Graph<T>::Vertex::addOutEdge(Edge e) {
  for (auto& ee : out_edges) {
    if (e == e) {
      // Edge already exists
      return;
    }
  }
  out_edges.push_back(e);
}