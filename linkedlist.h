#pragma once
#include <iostream>
#include "node.h"

namespace dstl {
    template<typename T>
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insert_at_beg(T);
        void insert_at_end(T);
        void printlist();
        //void insert_after(Node *node);
    private:
        Node<T> *head;
    };
}