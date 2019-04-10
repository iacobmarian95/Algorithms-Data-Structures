#pragma once
#ifndef __HASHNODE
#define __HASHNODE

namespace hash_node {
	template<typename K, typename V>
	class HashNode {
	public:
		HashNode(const K& key, const V& value) : m_key(key), m_value(value), m_next(nullptr) {

		}

		K GetKey();
		V GetValue();
		void SetValue(V value);
		HashNode* GetNext();
		void SetNext(HashNode* next);
	private:
		K m_key;
		V m_value;

		HashNode* m_next;
	};
}

#include"HashNode.cpp"

#endif // !__HASHNODE
