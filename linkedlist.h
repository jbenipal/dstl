#pragma once
#include <iostream>
#include "node.h"

namespace dstl {
    template<typename T>
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void push_front(T);
        void push_back(T);
        void printlist();
        //void insert_after(Node *node);
    private:
        Node<T> *head;
    };
}