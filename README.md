# CS3012 - Software Engineering @ TCD 2019/2020

## Part 1 - simple LCA

In this part a simple binary search tree class is implemented that supports an lca query.

Lca is defined as follow: _For nodes u and v of tree T , query lca(u, v) returns the lowest common ancestor of u and v in T, that is, it returns the node farthest from the root that is an ancestor of both u and v, where node is also defined to be an ancestor of itself, i.e. lca(u,u) = u_

Definition is taken from Bender et al. (2005) _"Lowest common ancestors in trees and directed acyclic graphs"_.

[TreeNode class](/CS3012-LCA/tree_node.h)

[BST class](/CS3012-LCA/bst.h)

[Unit test for BST](/CS3012-LCA/CS3012-LCA-Test/bst_lca_test.cpp)