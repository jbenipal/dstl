#include "linkedlist.h"

namespace dstl {
    template<typename T>
    LinkedList<T>::LinkedList()
        : head(nullptr)
    {}

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        Node<T> *runner = head;
        while (runner)
        {
            Node<T> *temp = runner;
            runner = runner->next;
            delete temp;
        }
    }

    template<typename T>
    void
        LinkedList<T>::push_front(T item)
    {
            Node<T> *n = new Node<T>();
            n->item = item;
            n->next = head;
            head = n;
        }

    template<typename T>
    void
        LinkedList<T>::push_back(T item)
    {
            Node<T> *n = head;
            if (head == nullptr)
            {
                push_front(item);
                return;
            }
            while (n->next != nullptr) n = n->next;
            n->next = new Node<T>();
            n->next->item = item;
            n->next->next = nullptr;
        }

    template<typename T>
    void LinkedList<T>::printlist()
    {
        Node<T> *runner = head;
        while (runner)
        {
            std::cout << runner->item << std::endl;
            runner = runner->next;
        }
    }

    template class LinkedList<int>;
    template class LinkedList<double>;
}