#include<iostream>
#include<string>
#include "HashMap.h"

int main()
{
	hash_map::HashMap<int, std::string> myHashMap;

	myHashMap.Insert(1, "First");
	myHashMap.Insert(2, "Second");

	auto firstNode = myHashMap.GetNode(1, "First");
	auto secondNode = myHashMap.GetNode(2, "Second");

	if (firstNode != nullptr)
		std::cout << firstNode->GetKey() << ' ' << firstNode->GetValue() << std::endl;

	if (secondNode != nullptr)
		std::cout << secondNode->GetKey() << ' ' << secondNode->GetValue() << std::endl;

	myHashMap.Remove(1, "First");

	firstNode = myHashMap.GetNode(1, "First");
	if (firstNode == nullptr)
		std::cout << "The node was deleted successfully" << std::endl;

	secondNode = myHashMap.GetNode(2, "Second");
	return 0;
}