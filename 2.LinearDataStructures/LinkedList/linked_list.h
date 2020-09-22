#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <class T>
class Node{
    private: 
        T value; 
        Node<T> *next; //Apuntador al siguiente nodo
    public: 
        ~Node<T>(); 
        Node<T>(T pValue, Node<T> *pNext); 
        T getValue(); 
        Node<T>* getNext(); 
        void setValue(T value); 
        void setNext(Node <T> *next); 
};

template <class T>
class LinkedList{
    private: 
        Node<T> *head; 
        Node<T> *tail; 

    public: 
        ~LinkedList(); 
        LinkedList(); 
        int length(); 
        void push(T pValue); 
        
};

#endif