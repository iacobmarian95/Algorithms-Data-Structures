#pragma once
#include"HashMap.h"

#ifndef __HASHMAP_IMPLEMETATION
#define __HASHMAP_IMPLEMETATION

template<typename K, typename V, typename F>
hash_node::HashNode<K, V>* hash_map::HashMap<K, V, F>::GetNode(const K& key, const V& value) const{
	hash_node::HashNode<K, V>* entry = m_table[hashFunc(key)];
	while (entry != nullptr) {
		if (entry->GetValue() == value && entry->GetKey() == key)
			break;
		entry = entry->GetNext();
	}

	return entry;
}

template<typename K, typename V, typename F>
bool hash_map::HashMap<K, V, F>::Insert(const K& key, const V& value) {
	//If the node exist we will return true, otherwise we will create a new node and will insert it into table
	int idx = hashFunc(key);
	hash_node::HashNode<K, V>* entry = m_table[idx];

	while (entry != nullptr) {
		if (entry->GetKey() == key) {
			entry->SetValue(value);
			return true;
		}
		entry = entry->GetNext();
	}

	hash_node::HashNode<K, V> *newNode = new hash_node::HashNode<K, V>(key, value);
	if (newNode == nullptr)
		return false;

	if (m_table[idx] == nullptr) {
		m_table[idx] = newNode;
	}
	else {
		entry = m_table[idx];
		newNode->SetNext(entry);
		entry = newNode;
	}

	return true;
}

template<typename K, typename V, typename F>
void hash_map::HashMap<K, V, F>::Remove(const K& key, const V&  value) {
	auto idx = hashFunc(key);

	hash_node::HashNode<K, V> *entry = m_table[idx];
	hash_node::HashNode<K, V> *prev = nullptr;

	while (entry != nullptr) {
		if(entry->GetKey() == key && entry->GetValue() == value) {
			break;
		}
		prev = entry;
		entry = entry->GetNext();
	}

	if (entry == nullptr)
		return;

	if (prev == nullptr) {
		m_table[idx] = entry->GetNext();
		delete entry;
	}
	else {
		prev->SetNext(entry->GetNext());
		delete entry;
	}
}

template<typename K, typename V, typename F>
hash_map::HashMap<K, V, F>::~HashMap(){
	for (auto it = 0; it < TABLE_SIZE; ++it) {
		hash_node::HashNode<K, V>* entry = m_table[it];
		while (entry != nullptr) {
			hash_node::HashNode<K, V>* temp = entry;
			entry = entry->GetNext();
			
			delete temp;
		}
		m_table[it] = nullptr;
	}
}
#endif