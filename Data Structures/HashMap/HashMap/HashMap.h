#pragma once
#ifndef __HashMap
#include"HashNode.h"

#define __HashMap

namespace hash_map {
	const int TABLE_SIZE = 1024;

	namespace hashFunction {
		template<typename K>
		class HashKey {
		public:
			unsigned long operator()(const K& key) const{
				return static_cast<unsigned long>(key) % TABLE_SIZE;
			}
		};
	}

	template<typename K, typename V, typename F = hashFunction::HashKey<K>>
	class HashMap {
	public:
		HashMap() {

			m_table = new hash_node::HashNode<K, V> *[TABLE_SIZE]();
		}

		hash_node::HashNode<K, V>* GetNode(const K& key, const V& value) const;
		//Return true if the operation hs been succeded		
		bool Insert(const K& key, const V& value);
		void Remove(const K& key, const V& value);

		~HashMap();
	private:
		hash_node::HashNode<K, V> ** m_table;
		F hashFunc;
	};
}
#include"HashMap.cpp"
#endif