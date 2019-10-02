#pragma once

#include "tree_node.h"

// author: Jevgenijus Cistiakovas

// A simple generic Binary Search Tree.
// TODO(j.cistiakovas): Add documentation.
template <typename T>
class BST {
 public:
  BST() : root_(nullptr) {}
  BST(TreeNode<T> node) : root_(node) {}
  void insertNode(T val);
  // returns nullptr if not found
  TreeNode<T>* search(T val);
  bool isEmpty();
  bool contains(T val);
  // Definition: 
  //   For nodes u and v of tree T , query lca(u, v) returns 
  //   the lowest common ancestor of u and v in T, that is,
  //   it returns the node farthest from the root that is 
  //   an ancestor of both u and v, where node is also defined
  //   to be an ancestor of itself, i.e. lca(u,u) = u.
  TreeNode<T>* lca(T val1, T val2);
  // Use this for easier nesting such as lca(a,lca(b,c)).
  TreeNode<T>* lca(T val1, TreeNode<T>* val2_ptr);

 private:
  TreeNode<T>* root_;

  struct lcaResult {
    TreeNode<T>* result = nullptr;
    bool seen_val1 = false;
    bool seen_val2 = false;
  };

  TreeNode<T>* searchUtil(TreeNode<T>* root, T val);
  TreeNode<T>* insertUtil(TreeNode<T>* root, T val);
  typename BST<T>::lcaResult lcaUtil(TreeNode<T>* root, T val1, T val2);
};

template <typename T>
void BST<T>::insertNode(T val) {
  root_ = insertUtil(root_, val);
}

template <typename T>
TreeNode<T>* BST<T>::insertUtil(TreeNode<T>* root, T val) {
  if (!root) {
    auto* new_node = new TreeNode<T>(val);
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
    return searchUtil(root->right_, val);
  }
}

template <typename T>
bool BST<T>::isEmpty() {
  return !root_;
}

template <typename T>
bool BST<T>::contains(T val) {
  return search(val);
}

template <typename T>
TreeNode<T>* BST<T>::lca(T val1, T val2) {
  auto res = lcaUtil(root_, val1, val2);
  return res.result;
}

template <typename T>
typename BST<T>::lcaResult BST<T>::lcaUtil(TreeNode<T>* root, T val1, T val2) {
  struct BST<T>::lcaResult res;
  if (!root) {
    return res;
  }
  T data = root->getData();
  if (data == val1) {
    res.seen_val1 = true;
  }
  if (data == val2) {
    res.seen_val2 = true;
  }
  if (res.seen_val1 && res.seen_val2) {
    res.result = root;
    return res;
  }
  auto left_res = lcaUtil(root->left_, val1, val2);
  auto right_res = lcaUtil(root->right_, val1, val2);
  if (left_res.result) {
    return left_res;
  }
  if (right_res.result) {
    return right_res;
  }
  res.seen_val1 |= left_res.seen_val1 || right_res.seen_val1;
  res.seen_val2 |= left_res.seen_val2 || right_res.seen_val2;

  if (res.seen_val1 && res.seen_val2) {
    res.result = root;
  }
  return res;
}

template <typename T>
TreeNode<T>* BST<T>::lca(T val1, TreeNode<T>* val2_ptr) {
  if (!val2_ptr) {
    return val2_ptr;
  }
  return lca(val1, val2_ptr->getData());
}
