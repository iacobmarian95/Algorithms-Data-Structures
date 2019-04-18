#pragma once

namespace avl_node {
	
	template<typename T>
	class Node {
	public:
		Node();
		
		Node(T value);
		Node(Node& node);
		void operator=(const Node& node);

		T GetValue();
		void SetValue(T value);
		int GetHeight();
		void SetHeight(int value);
		Node* GetLeft();
		Node* GetRight();
		void SetLeft(Node* left);
		void SetRight(Node* right);

		~Node();
	private:
		T m_value;
		unsigned int m_height;
		Node* m_left;
		Node* m_right;
	};

#include"Node.cpp"
}