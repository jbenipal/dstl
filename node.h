#ifndef _NODE_H
#define _NODE_H

//in future use #pragma once

template<typename U>
struct Node
{
    U item;
    Node<U> *next;
};

template<typename U>
struct BinaryNode {
    U item;
    BinaryNode<U> *left;
    BinaryNode<U> *right;
};

template struct Node<int>;
template struct Node<double>;

template struct BinaryNode<int>;
template struct BinaryNode<double>;

#endif