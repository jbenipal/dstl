#pragma once
#include "node.h"
#include <iostream>

namespace dstl {
    template <typename T>
    class BST {
    public:
        BST() : root(nullptr){ }
        ~BST() {
            deletetree(root);
        }
        void insert(T item);
        void deleteitem(T item);
        BinaryNode<T>* insert(T item, BinaryNode<T> *node);
        BinaryNode<T>* deleteitem(T item, BinaryNode<T> *node);

        void inorder();
        void inorder(BinaryNode<T>* node);
        BinaryNode<T>* getroot() const { return root; }

    private:
        BinaryNode<T> *root;
        BinaryNode<T>* findsmallest(BinaryNode<T> *node);
        void deletetree(BinaryNode<T> *node);
    };
}