#include"Node.h"

#ifndef __Node_Impl
#define __Node_Impl

template<typename T>
avl_node::Node<T>::Node() : m_value(0), m_left(nullptr), m_right(nullptr), m_height(1) {

}

template<typename T> 
avl_node::Node<T>::Node(T value): m_value(value), m_left(nullptr), m_right(nullptr), m_height(1) {

}

template<typename T> 
avl_node::Node<T>::Node(Node& node) {
	this->m_value = node.m_value;
	this->m_height = node.m_height;
	this->m_left = node.m_left;
	this->m_right = node.m_right;
}

template<typename T>
void avl_node::Node<T>::operator=(const Node& node) {
	this->m_value = node.m_value;
	this->m_height = node.m_height;
	this->m_left = node.m_left;
	this->m_right = node.m_right;
}

template<typename T>
T avl_node::Node<T>::GetValue() {
	return m_value;
}

template<typename T>
void avl_node::Node<T>::SetValue(T value) {
	m_value = value;
}

template<typename T>
int avl_node::Node<T>::GetHeight() {
	return m_height;
}

template<typename T>
void avl_node::Node<T>::SetHeight(int value) {
	m_height = value;
}

template<typename T>
avl_node::Node<T>* avl_node::Node<T>::GetLeft() {
	return m_left;
}

template<typename T>
avl_node::Node<T>* avl_node::Node<T>::GetRight() {
	return m_right;
}

template<typename T>
void avl_node::Node<T>::SetLeft(avl_node::Node<T>* node) {
	m_left = node;
}

template<typename T>
void avl_node::Node<T>::SetRight(avl_node::Node<T>* node) {
	m_right = node;
}

template<typename T>
avl_node::Node<T>::~Node() {
	m_value = 0;
	m_height = 0;
	m_left = nullptr;
	m_right = nullptr;
}
#endif