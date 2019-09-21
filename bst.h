#pragma once

#include <iostream>

#include "tree_node.h"

/*
	author: Jevgenijus Cistiakovas
*/

// A simple generic Binary Search Tree
template<typename T>
class BST
{
public:
	BST() = default;
	BST(TreeNode<T> node) : root_(node) {}
	void insertNode(T val);
	// returns nullptr if not found
	TreeNode<T>* search(T val);
	bool isEmpty();
	bool contains(T val);
	TreeNode<T>* lca(T val1, T val2);
	// Use this for easier nesting such as lca(a,lca(b,c)
	TreeNode<T>* lca(T val1, TreeNode<T>* val2_ptr);
private:
	TreeNode<T>* root_;
};

