#pragma once

#include "tree_node.h"

// author: Jevgenijus Cistiakovas

// A simple generic Binary Search Tree
template<typename T>
class BST
{
public:
  BST() : root_(nullptr) {}
	BST(TreeNode<T> node) : root_(node) {}
	void insertNode(T val);
	// returns nullptr if not found
	TreeNode<T>* search(T val);
	bool isEmpty();
	bool contains(T val);
	TreeNode<T>* lca(T val1, T val2);
	// Use this for easier nesting such as lca(a,lca(b,c))
	TreeNode<T>* lca(T val1, TreeNode<T>* val2_ptr);
private:
	TreeNode<T>* root_;
	TreeNode<T>* searchUtil(TreeNode<T>* root, T val);
  TreeNode<T>* insertUtil(TreeNode<T>* root, T val);
};

template <typename T>
void BST<T>::insertNode(T val) {
  root_ = insertUtil(root_, val);
}

template <typename T>
TreeNode<T>* BST<T>::insertUtil(TreeNode<T>* root, T val) {
  if (!root) {
    auto * new_node = new TreeNode<T>(val);
    return new_node;
  }
  T data = root->getData();
  if (val < data) {
    auto* node = insertUtil(root->left_, val);
    root->left_ = node;
    return root;
  } else if (val > data) {
    auto* node = insertUtil(root->right_, val);
    root->right_ = node;
    return root;
  } else {
    return root;
  }
}

template <typename T>
TreeNode<T>* BST<T>::search(T val) {
  return searchUtil(root_, val);
}

template <typename T>
TreeNode<T>* BST<T>::searchUtil(TreeNode<T>* root, T val) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->getData() == val) {
    return root;
  }

  T data = root->getData();
  if (val < data) {
    return searchUtil(root->left_, val);
  } else {
    return searchUtil(root->right_,val);
  }
}

template <typename T>
bool BST<T>::isEmpty() {
  return false;
}

template <typename T>
bool BST<T>::contains(T val) {
  return search(val) != nullptr;
}

template <typename T>
TreeNode<T>* BST<T>::lca(T val1, T val2) {
  return nullptr;
}

template <typename T>
TreeNode<T>* BST<T>::lca(T val1, TreeNode<T>* val2_ptr) {
  return nullptr;
}
