#pragma once

// author: Jevgenijus Cistiakovas

template<typename T>
class BST;

template<typename T>
class TreeNode {
  friend class BST<T>;
 public:
	TreeNode(T data) :
		data_(data), left_(nullptr), right_(nullptr){}
	T getData() {
		return data_;
	}
private:
	T data_;
	TreeNode<T>* left_;
	TreeNode<T>* right_;
};