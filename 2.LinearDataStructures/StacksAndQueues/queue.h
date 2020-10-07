#ifndef _QUEUE_H 
#define _QUEUE_H 
#include "../LinkedList/linked_list.h"

template <class T>
class Queue : public LinkedList<T>{
    public: 
        ~Queue() {}; 
        Queue() {}; 

        void enqueue(T){
            this->push(T); 
        }; 

        T dequeue(){
            // devolver el elemento del inicio
        Node<T> *current = this->head;

        if (current == NULL)
        {
            throw "Queue is empty";
        }

        if (ptr->get_next() == NULL)
        {
            T res = current->get_val();
            delete current;
            this->head = NULL;
            return res;
        }

        Node<T> *prev = NULL;
        while (current->get_next() != NULL)
        {
            prev = current;
            current = current->get_next();        
        }
        T res = current->get_val();

        // eliminar el elemento del inicio
        delete current;
        prev->set_next(NULL);

        return res;
    };
    protected:
        using LinkedList<T>::push;
        using LinkedList<T>::insert_item;
        using LinkedList<T>::delete_item;
        using LinkedList<T>::append;
        using LinkedList<T>::get_nth;

};
#endif