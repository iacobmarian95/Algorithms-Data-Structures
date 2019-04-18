#include"AvlTree.h"
#ifndef __AvlTree_Impl
#define __AvlTree_Impl

template<typename T>
avl_tree::AvlTree<T>::AvlTree(): m_root(nullptr) {
}

template<typename T>
void avl_tree::AvlTree<T>::Insert(T value) {
	m_root = insert(m_root, value);
}

template<typename T>
void avl_tree::AvlTree<T>::Delete(T value) {
	m_root = _delete(m_root, value);
}

template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::balance(avl_node::Node<T>* root, T& value) {
	root->SetHeight(std::max(getHeight(root->GetLeft()), getHeight(root->GetRight())) + 1);

	//balance factor
	int balance = getBalance(root);

	//1. One right rotation
	if (balance > 1 && value < root->GetLeft()->GetValue()) {
		return rightRotation(root);
	}
	//2. One left rotation on the root->left and one right rotation on the root
	if (balance > 1 && value > root->GetLeft()->GetValue()) {
		root->SetLeft(leftRotation(root->GetLeft()));
		return rightRotation(root);
	}

	//3. One left rotation
	if (balance < -1 && value > root->GetRight()->GetValue()) {
		return leftRotation(root);
	}

	//4. One right rotation on the right soon and after that on left rotation 
	if (balance < -1 && value < root->GetRight()->GetValue()) {
		root->SetRight(rightRotation(root->GetRight()));
		return leftRotation(root);
	}

	return root;
}

template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::insert(avl_node::Node<T>* root, T& value) {
	if (root == nullptr)
		return new avl_node::Node<T>(value);

	if (value < root->GetValue())
		root->SetLeft(insert(root->GetLeft(), value));
	else if (value > root->GetValue())
		root->SetRight(insert(root->GetRight(), value));
	else
		return root;

	return balance(root, value);
}

template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::_delete(avl_node::Node<T>* root, T value) {
	if (root == nullptr)
		return nullptr;

	if (value < root->GetValue())
		root->SetLeft(_delete(root->GetLeft(), value));
	else if (value > root->GetValue())
		root->SetRight(_delete(root->GetRight(), value));
	else {
		if (root->GetLeft() == nullptr || root->GetRight() == nullptr) {
			avl_node::Node<T>* temp = root->GetLeft() != nullptr ? root->GetLeft() : root->GetRight();
			if (temp == nullptr) {
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;
			delete temp;
		}
		else {
			avl_node::Node<T>* temp = getMinOnTheRight(root);

			root->SetValue(temp->GetValue());
			root->SetRight(_delete(root->GetRight(), temp->GetValue()));
		}
	}

	if (root == nullptr)
		return nullptr;

	return balance(root, value);
}

template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::getMinOnTheRight(avl_node::Node<T>* root) {
	avl_node::Node<T>* iterator = root->GetRight();
	while (iterator->GetLeft() != nullptr)
		iterator = iterator->GetLeft();

	return iterator;
}


template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::leftRotation(avl_node::Node<T>* root) {
	std::cout << "One left rotation was made" << std::endl;

	avl_node::Node<T>* rightSon = root->GetRight();
	avl_node::Node<T>* leftGrandSon = rightSon->GetLeft();

	rightSon->SetLeft(root);
	root->SetRight(leftGrandSon);

	//update the height of the left soon now
	root->SetHeight(std::max(getHeight(root->GetLeft()), getHeight(root->GetRight())) + 1);
	//and for the new root
	rightSon->SetHeight(std::max(getHeight(rightSon->GetLeft()), getHeight(rightSon->GetRight())) + 1);

	return rightSon;
}

template<typename T>
avl_node::Node<T>* avl_tree::AvlTree<T>::rightRotation(avl_node::Node<T>* root) {
	std::cout << "One right rotation was made" << std::endl;
	avl_node::Node<T>* leftSon = root->GetLeft();
	avl_node::Node<T>* rightGrandSon = leftSon->GetRight();

	leftSon->SetRight(root);
	root->SetLeft(rightGrandSon);

	//update the heights
	root->SetHeight(std::max(getHeight(root->GetLeft()), getHeight(root->GetRight())) + 1);
	leftSon->SetHeight(std::max(getHeight(leftSon->GetLeft()), getHeight(leftSon->GetRight())) + 1);

	return leftSon;
}

template<typename T>
int avl_tree::AvlTree<T>::getBalance(avl_node::Node<T>* node) {
	return getHeight(node->GetLeft()) - getHeight(node->GetRight());
}

template<typename T>
void avl_tree::AvlTree<T>::cleanUp(avl_node::Node<T> *root) {
	if (root == nullptr)
		return;

	cleanUp(root->GetLeft());
	cleanUp(root->GetRight());

	delete root;
}

template<typename T>
unsigned int avl_tree::AvlTree<T>::getHeight(avl_node::Node<T>* node) {
	if (node != nullptr)
		return node->GetHeight();
	return 0;
}

template<typename T>
avl_tree::AvlTree<T>::~AvlTree() {
	cleanUp(m_root);
}

#endif // !__AvlTree_Impl