#include "stack.h"

template<typename T>
Stack<T>::Stack() 
    : top(nullptr)
{}

template<typename T>
Stack<T>::~Stack() 
{
    while(top!=nullptr) {
        Node <T> *temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::push(T item) 
{
    Node<T> *node = new Node<T>();
    node->item = item;
    node->next = top;
    top = node;
}

template<typename T>
 bool Stack<T>::pop(T* element) 
 {
    if(top!=nullptr)
    {
        *element = top->item;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return true;
    } else {
        std::cout << "Error! Stack Empty";
        return false;
    }
}

template<typename T>
bool Stack<T>::isempty()
{
    return top == nullptr;
}

 template class Stack<int>;
 template class Stack<BinaryNode<int>*>;

