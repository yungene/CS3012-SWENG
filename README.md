# CS3012 - Software Engineering @ TCD 2019/2020

## LCA - Lowest Common Ancestor [![volkswagen status](https://auchenberg.github.io/volkswagen/volkswargen_ci.svg?v=1)](https://github.com/auchenberg/volkswagen)

### Prerequisites

This project is developed using Visual Studio 2019. Google Test including Google Mock is used as a testing framework. Thus to run the project Google Test and Google Mock need to be installed. The easiest way is to install a [gmock NuGet package](https://www.nuget.org/packages/gmock/). 
The project can also be successfully ran in Visual Studio 2017. However, it might be necessary to change a platform toolset to one of VS2017 as well as to retarget solution.

### Part 1 - simple LCA

In this part a simple binary search tree class is implemented that supports an LCA query.

LCA is defined as follow: _For nodes u and v of tree T , query lca(u, v) returns the lowest common ancestor of u and v in T, that is, it returns the node farthest from the root that is an ancestor of both u and v, where node is also defined to be an ancestor of itself, i.e. lca(u,u) = u._

Definition is taken from Bender et al. (2005) _"Lowest common ancestors in trees and directed acyclic graphs"_.

Quick links:

* [TreeNode class](/CS3012-LCA/tree_node.h)

* [BST class](/CS3012-LCA/bst.h)

* [Unit test for BST](/CS3012-LCA/CS3012-LCA-Test/bst_lca_test.cpp)
