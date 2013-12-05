#include "hashtable.h"

template <typename T, typename U>
HashTable<T,U>::HashTable()
{
	for(int i=0;i<MAX_SIZE;++i) {
		hashtable[i] = nullptr;
	}
}

template <typename T, typename U>
HashTable<T,U>::~HashTable()
{
	for(int index=0;index<MAX_SIZE;++index) {
		HashNode<T,U>* node = hashtable[index];
		while(node != nullptr) {
			HashNode<T,U>* temp = node;
			node = node->next;
			delete temp;
		}
		hashtable[index] = nullptr;
	}
}

template <typename T, typename U>
void HashTable<T,U>::insert(T key, U value)
{
	int index = hashfunction(key);
	if(hashtable[index] == nullptr) {
		HashNode<T,U>* node = new HashNode<T,U>(key, value);
		node->next = nullptr;
		hashtable[index] = node;
	} else {
		HashNode<T,U>* node = hashtable[index];
		while(node != nullptr && node->key != key) {
			node = node->next;
		}
		if(node == nullptr) {
			HashNode<T,U>* node = new HashNode<T,U>(key, value);
			node->next = hashtable[index];
			hashtable[index] = node;
		}
		else {
			// Overwrite
			node->value = value;
		}
	}
}

template <typename T, typename U>
U HashTable<T,U>::get(T key)
{
	int index = hashfunction(key);
	if(hashtable[index] == nullptr) {
		return INT_MIN; //:P
	} else {
		HashNode<T,U>* node = hashtable[index];
		while(node != nullptr && node->key != key) {
			node = node->next;
		}
		if(node == nullptr) {
			return INT_MIN;
		} else {
			return node->value;
		}
	}
}

template <typename T, typename U>
int HashTable<T,U>::hashfunction(T key)
{
	//TODO/XXX/
	//stupid hash function
	return key % MAX_SIZE;
}

template class HashTable<int, int>;
//template class HashTable<std::string, int>;