#pragma once

#include <iostream>

#include "tree_node.h"

/*
	author: Jevgenijus Cistiakovas
*/

template<class T>
class BST
{
public:
	Tree() = default;
	void insertNode(T val);
	// returns nullptr if not found
	TreeNode<T>* search(T val);
	bool isEmpty();
	bool contains(T val);
	TreeNode<T>* lca(T val1, T val2);
private:
	TreeNode<T>* root_;
};

