#include<iostream>
#include "node.h"

template<typename T>
class BinaryTree {
public:
    BinaryTree();
    virtual ~BinaryTree();

    void preorder();
    void inorder();
    void postorder();
    void levelorder();
    void preorder_r() { 
        std::cout <<"PreOrder:";
        preorder_recursive(root); 
        std::cout << std::endl; 
    }
    void inorder_r() { 
        std::cout <<"In Order:"; 
        inorder_recursive(root); 
        std::cout << std::endl; 
    }
    void postorder_r() { 
        std::cout << "Post Order:"; 
        postorder_recursive(root); 
        std::cout << std::endl; 
    }
    void createtree();
    void printallpaths(T path[], int pathLen) {
        printpath(root, path, pathLen);
    }
    bool checkpathsum2(int sum) { return checkpathsum(sum, root); }
    void mirror2() { mirror(root); }
    void setroot(BinaryNode<T>* root_) { root = root_; }
    BinaryNode<T>* LCA(BinaryNode<T>* root, int i, int j);
    BinaryNode<T>* LCA(int i, int j)
    {
        return LCA(root, i, j);
    }

    BinaryNode<T>* buildtree(T inorder[], T preorder[], int start, int end);
private:
    void deletetree(BinaryNode<T>*);
    void preorder_recursive(BinaryNode<T>* node);
    void inorder_recursive(BinaryNode<T>* node);
    void postorder_recursive(BinaryNode<T>* node);
    void printpath(BinaryNode<T>* node, T path[], int pathLen);
    void printarray(T path[], int pathLen);
    bool checkpathsum(int, BinaryNode<T> *);
    void mirror(BinaryNode<T> *);

    BinaryNode<T> *root;
    int preindex;
};