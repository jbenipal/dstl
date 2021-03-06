#pragma once
#include <iostream>
#include "node.h"

namespace dstl{
    template<typename T>
    class Queue {
    public:
        Queue();
        ~Queue();
        void enque(T);
        void deque(T *);
        bool isempty();
    private:
        Node<T> *front;
        Node<T> *rear;
    };
}