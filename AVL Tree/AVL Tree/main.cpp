#include<iostream>
#include"AvlTree.h"

int main() {
	avl_tree::AvlTree<int> tree;
	tree.Insert(12);
	tree.Insert(8);
	tree.Insert(6);
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(1);

	tree.Delete(4);

	return 0;
}