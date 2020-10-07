#ifndef _STACK_H 
#define _STACK_H 
#include "linked_list.h"

template <class T>
class Stack : public LinkedList<T>{
    public: 
    Stack() {};
    ~Stack() {}; 

    T pop(){
        if(this->isEmpty()){
            throw "Stack is empty";
        };
        T res = this->head->getValue(); 
        this->deleteItem(0); 
        return res; 
    };

    T peek(){
        if (this->isEmpty()) {
            throw "Stack is empty";
        }
        return this->head->getValue(); 
    }; 

    protected:
    using LinkedList<T>::insertItem;
    using LinkedList<T>::deleteItem;
    using LinkedList<T>::append;
    using LinkedList<T>::getNth;

}; 

#endif