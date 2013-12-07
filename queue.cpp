#include "queue.h"

namespace dstl {
    template<typename T>
    Queue<T>::Queue()
        : front(nullptr)
        , rear(nullptr)
    {
    }

    template<typename T>
    Queue<T>::~Queue()
    {
        while (front != rear) {
            Node <T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    template<typename T>
    void Queue<T>::enque(T item)
    {
        Node<T> *node = new Node<T>();
        node->item = item;
        node->next = nullptr;
        if (rear) rear->next = node;
        rear = node;
        if (front == nullptr) {
            front = rear;
        }
    }

    template<typename T>
    void Queue<T>::deque(T* element)
    {
        if (front != nullptr)
        {
            *element = front->item;
            Node<T>* temp = front;
            if (rear == front) rear = nullptr;
            front = front->next;
            delete temp;
        } else {
            std::cout << "Error! Queue Empty";
        }
    }

    template<typename T>
    bool Queue<T>::isempty()
    {
        return front == nullptr && rear == nullptr;
    }

    template class Queue<int>;
    template class Queue<BinaryNode<int>*>;
}