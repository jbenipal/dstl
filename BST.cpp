#include "BST.h"

template <class T>
void BST<T>::insert(T item) { 
	root = insert(item, root);
}

template <class T>
void BST<T>::deleteitem(T item) { 
	root = deleteitem(item, root); 
}

template <class T>
void BST<T>::inorder() {
	inorder(root);
}

template <class T>
BinaryNode<T>* BST<T>::insert(T item, BinaryNode<T> *node)
{
	if(node==nullptr)
	{
		BinaryNode<T>* node = new BinaryNode<T>();
		node->item = item;
		node->left = node->right = nullptr;
		return node;
	}
	if(item <= node->item) {
		node->left = insert(item, node->left);
	}
	else {
		node->right = insert(item, node->right);
	}
	return node;
}

template <class T>
BinaryNode<T>* BST<T>::deleteitem(T item, BinaryNode<T>* node)
{
	if(node == nullptr)
		return node;
	if(item < node->item) {
		node->left = deleteitem(item, node->left);
	}
	else if(item > node->item) {
		node->right = deleteitem(item, node->right);
	} else {
		if(node->left != nullptr && node->right != nullptr) {
			BinaryNode<T>* temp = findsmallest(node->right);
			node->item = temp->item;
			node->right = deleteitem(temp->item, node->right);
		} else if (node->left == nullptr) {
			BinaryNode<T>* temp = node;
			node = node->right;
			delete temp;
		} else { //node->right == nullptr
			BinaryNode<T>* temp = node;
			node = node->left;
			delete temp;
		}
	}
	return node;
}

template <class T>
BinaryNode<T>* BST<T>::findsmallest(BinaryNode<T> *node)
{
	if(node == nullptr)
		return node;
	if(node->left != nullptr)
		return findsmallest(node->left);
	else
		return node;
}

template<typename T>
void BST<T>::inorder(BinaryNode<T>* node)
{
	if(node!=nullptr)
	{
		inorder(node->left);
		std::cout << node->item << " ";
		inorder(node->right);
	}
}

template<typename T>
void BST<T>::deletetree(BinaryNode<T>* node)
{
	if(node!=nullptr)
	{
		deletetree(node->left);
		deletetree(node->right);
		delete node;
	}
}

template class BST<int>;