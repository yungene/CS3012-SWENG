#pragma once

#include <vector>

// author: Jevgenijus Cistiakovas cistiakj


// Note: This graph only allows for nodes with unique values. 
// TODO(cistiakj): consider allowing nodes to have non-unique values. 
//                      This means using some type of key to uniquely identify nodes.
template <typename T>
class Graph {
 public:
  bool addVertex(T const& value);
  bool addVertex(T&& value);
  bool addEdge(T const& src, T const& dest);
  bool isDag();
  bool isEmpty();
  // Definition as of Bender et al. 2005 "Lowest common ancestors in trees and directed acyclic graphs"
  // An LCA w of nodes u and v in a DAG is an ancestor of both u and v 
  // where w has no descendants that are also ancestors of both u and v.
  // Note: assume lca(x,x) = x, i.e. lca is reflexive
  std::vector<T> lca(T const& u, T const& v);
 private:
};

