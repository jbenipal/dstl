#pragma once 

#include <iostream>
#include "node.h"

namespace dstl {
    template<typename T>
    class Stack {
    public:
        Stack();
        ~Stack();
        bool pop(T *);
        void push(T);
        bool isempty();
    private:
        Node<T> *top;
    };
}