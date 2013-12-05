#include "binarytree.h"
#include "stack.h"
#include "queue.h"

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
	preindex = 0;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
	deletetree(root);
}

template<typename T>
void BinaryTree<T>::deletetree(BinaryNode<T>* node) 
{
	if(node)
	{
		deletetree(node->left);
		deletetree(node->right);
		delete node;
	}
}

template<typename T>
void BinaryTree<T>::preorder_recursive(BinaryNode<T>* node)
{
	if(node!=nullptr)
	{
		std::cout << node->item << " ";
		preorder_recursive(node->left);
		preorder_recursive(node->right);
	}
}

template<typename T>
void BinaryTree<T>::inorder_recursive(BinaryNode<T>* node)
{
	if(node!=nullptr)
	{
		inorder_recursive(node->left);
		std::cout << node->item << " ";
		inorder_recursive(node->right);
	}
}

template<typename T>
void BinaryTree<T>::postorder_recursive(BinaryNode<T>* node)
{
	if(node!=nullptr)
	{
		postorder_recursive(node->left);
		postorder_recursive(node->right);
		std::cout << node->item << " ";
	}
}

//shud print 1 2 4 5 3 6 7
template<typename T>
void BinaryTree<T>::preorder()
{
	Stack<BinaryNode<T>*> stack;
	std::cout << "Pre Order:";
	if(root) stack.push(root);
	while(!stack.isempty())
	{
		BinaryNode<T>* temp;
		stack.pop(&temp);
		std::cout << temp->item << " ";
		if(temp->right) stack.push(temp->right);
		if(temp->left) stack.push(temp->left);
	}
	std::cout << std::endl;
}

//shud print 4 2 5 1 6 3 7
template<typename T>
void BinaryTree<T>::inorder()
{
	Stack<BinaryNode<T>*> stack;
	BinaryNode<T>* current = root;
	std::cout << "InOrder:";
	while(!stack.isempty() || current != nullptr)
	{
		while(current != nullptr) {
			stack.push(current);
			current = current->left;
		}
		stack.pop(&current);
		std::cout << current->item << " ";
		current = current->right;
	}
	std::cout << std::endl;
}

//shud print 4 5 2 6 7 3 1
template<typename T>
void BinaryTree<T>::postorder()
{
	Stack<BinaryNode<T>*> stack;
	BinaryNode<T>* current = nullptr;
	BinaryNode<T>* last = root;
	std::cout << "PostOrder:";
	stack.push(root);
	while(!stack.isempty()) 
	{
		stack.pop(&current);
		if (current->right == last || current->left == last ||
			(current->left == nullptr && current->right == nullptr))
		{
			std::cout << current->item << " ";
			last = current;
		} else {		
			stack.push(current);
			if (current->right != nullptr)
				stack.push(current->right);
			if (current->left != nullptr)
				stack.push(current->left);
		}
	}
	std::cout << std::endl;
}

template<typename T>
void BinaryTree<T>::levelorder()
{
	Queue<BinaryNode<T> *> queue;
	if(root) queue.enque(root);
	int curr_level = 1;
	int next_level = 0;
	while(!queue.isempty())
	{
		BinaryNode<T> *temp;
		queue.deque(&temp);
		--curr_level;
		std::cout << temp->item << " ";
		if(temp->left) {
			queue.enque(temp->left);
			++next_level;
		}

		if(temp->right) {
			queue.enque(temp->right);
			++next_level;
		}

		if(curr_level == 0) {
			std::cout << std::endl;
			curr_level = next_level;
			next_level = 0;
		}
	}
}

template <class T>
void BinaryTree<T>::printpath(BinaryNode<T>* node, T path[], int pathLen)
{
	if (node==nullptr) 
		return;
 
	path[pathLen] = node->item;
	pathLen++;
	if (node->left==nullptr && node->right==nullptr) 
	{
		printarray(path, pathLen);
	}
	else
	{
		printpath(node->left, path, pathLen);
		printpath(node->right, path, pathLen);
	}
}

template<typename T>
bool BinaryTree<T>::checkpathsum(int sum, BinaryNode<T>* node)
{
	if(node == nullptr) return false;
	sum -= node->item;
	if(sum == 0) return true;
	return checkpathsum(sum, node->left) || checkpathsum(sum, node->right);
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::buildtree(T inorder[], T preorder[], int start, int end)
{
	if(start > end) return nullptr;
	BinaryNode<T>* node = new BinaryNode<T>();
	node->item = preorder[preindex];
	++preindex;
	if(start == end) {
		node->left = node->right = nullptr;
		return node;
	}
	int left;
	//T r_item = preorder[start];
	T r_item = node->item;
	for(left=0;left<end;left++) {
		if(inorder[left] == r_item)
			break;
	}
	node->left = buildtree(inorder, preorder, start, left);
	node->right = buildtree(inorder, preorder, left+1, end);
	return node;
}

template<typename T>
void BinaryTree<T>::mirror(BinaryNode<T>* node)
{
	if(node == nullptr) return;
	else {
		BinaryNode<T> *temp = node->left;
		node->left = node->right;
		node->right = temp;
		mirror(node->left);
		mirror(node->right);
	}
}

template<typename T>
void BinaryTree<T>::printarray(T nodes[], int len)
{
	for (int i=0; i<len; i++) {
		std::cout << nodes[i];
	}
	printf("\n");
}    

template <class T>
BinaryNode<T>* BinaryTree<T>::LCA(BinaryNode<T>* node, int p, int q)
{
	if(node == nullptr)
		return nullptr;
	if(node->item == p || node->item == q)
		return node;

	BinaryNode<T>* left = LCA(node->left, p, q);
	BinaryNode<T>* right = LCA(node->right, p, q);
	if(left!=nullptr && right!=nullptr)
		return node;
	if(left!=nullptr) return left;
	
	return right;
}


/*
			1
		  /   \
		 2     3
		/ \   / \
	   4   5  6  7
*/
template<typename T>
void BinaryTree<T>::createtree()
{
	BinaryNode<T> *node = new BinaryNode<int>();
	node->item = 1;
	root = node;
	
	root->left = new BinaryNode<T>();
	root->right = new BinaryNode<T>();
	
	node = root->left;
	node->item = 2;
	node->left = new BinaryNode<T>();
	node->right = new BinaryNode<T>();
	
	node->left->item = 4;
	node->left->left = nullptr;
	node->left->right = nullptr;
	
	node->right->item = 5;
	node->right->left = nullptr;
	node->right->right = nullptr;

	node = root->right;
	node->item = 3;
	node->left = new BinaryNode<T>();
	node->right = new BinaryNode<T>();
	
	node->left->item = 6;
	node->left->left = nullptr;
	node->left->right = nullptr;
	
	node->right->item = 7;
	node->right->left = nullptr;
	node->right->right = nullptr;
}

template class BinaryTree<int>;