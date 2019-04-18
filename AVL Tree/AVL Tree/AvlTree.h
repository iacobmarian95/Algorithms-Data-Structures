#pragma once
#include"Node.h"
#include<algorithm>
#include<iostream>

namespace avl_tree {
	template<typename T>
	class AvlTree {
	public:
		AvlTree();

		void Insert(T value);
		void Delete(T value);

		~AvlTree();
	private:
		avl_node::Node<T>* insert(avl_node::Node<T>* root, T& value);
		avl_node::Node<T>* _delete(avl_node::Node<T>* root, T value);

		avl_node::Node<T>* balance(avl_node::Node<T>* root, T& value);

		avl_node::Node<T>* getMinOnTheRight(avl_node::Node<T>* root);

		void cleanUp(avl_node::Node<T>* root);
		
		unsigned int getHeight(avl_node::Node<T>* node);
		int getBalance(avl_node::Node<T>* node);

		avl_node::Node<T>* leftRotation(avl_node::Node<T>* root);
		avl_node::Node<T>* rightRotation(avl_node::Node<T>* root);


	private:
		avl_node::Node<T> *m_root;
	};

#include"AvlTree.cpp"
}