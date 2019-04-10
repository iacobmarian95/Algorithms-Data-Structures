#include"HashNode.h"
#ifndef __HASHNODE_IMPLEMENTATION
#define __HASHNODE_IMPLEMENTATION

template<typename K, typename V>
K hash_node::HashNode<K, V>::GetKey() {
	return m_key;
}

template<typename K, typename V>
V hash_node::HashNode<K, V>::GetValue() {
	return m_value;
}

template<typename K, typename V>
void hash_node::HashNode<K, V>::SetValue(V value) {
	m_value = value;
}

template<typename K, typename V>
hash_node::HashNode<K, V>* hash_node::HashNode<K, V>::GetNext() {
	return m_next;
}

template<typename K, typename V>
void hash_node::HashNode<K, V>::SetNext(hash_node::HashNode<K, V>* next) {
	m_next = next;
}

#endif // !__HASHNODE_IMPLEMENTATION

