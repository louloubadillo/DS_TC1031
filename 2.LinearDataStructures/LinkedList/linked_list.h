#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h> //para usar null
#include <iostream>
#include <vector> 

template <class T>
class Node{
    private: 
        T value; 
        Node<T> *next; //Apuntador al siguiente nodo
    public: 
        ~Node<T>() {}; 
        Node<T>(T pValue, Node<T> *pNext){
            value = pValue; 
            next = pNext; 
        }; 

        T getValue() {return value;}; 
        Node<T>* getNext() {return next;}; 
        void setValue(T pValue) {value = pValue;}; 
        void setNext(Node <T> *pNext) {next = pNext;}; 
};

template <class T>
class LinkedList{
    protected: 
        Node<T> *head; 

    public: 
        ~LinkedList() { 
            //TODO
        }; 
        LinkedList(){
            head = NULL; 
        }; 

        int length(){
            int length = 0;
            Node<T> *current = head;   
            while(current != NULL){
                length++; 
                current = current->getNext(); 
            }
            return length; 
        }; 

        void print(){
            Node<T> *current = head; 
            std::cout << "HEAD, "; 
            while(current != NULL){
                std::cout << current->getValue() << ", "; 
                current = current->getNext(); 
            }
            std::cout << "NULL" << std::endl; 
        }

        void push(T pValue){
            Node<T> *newNode = new Node<T>(pValue, head); 
            this->head = newNode; 
        }; 

        void append(T pValue){
            Node<T> *current = head; 
            while(current->getNext() != NULL){
                current = current->getNext(); 
            }
            Node<T> *node = new Node<T>(pValue, NULL);
            current->setNext(node); 
        }; 

        int insertItem(T pValue, int index){
            if(index >= length()){
                return -1; 
            }
            if(index < 0){
                return -2;
            }
            if(index == 0){
                push(pValue); 
                return 1; 
            }
            int counter = 0; 
            Node<T> *current = head; 
            Node<T> *prev = NULL; 
            while(current != NULL && index > counter){
                prev = current; 
                current = current->getNext(); 
                counter++; 
            }
            Node<T> *node = new Node<T>(pValue, current);
            prev->setNext(node); 
            return 1; 
        }; 

        bool isEmpty(){
            return head == NULL; 
        };

        int deleteItem(int index){
            if(index >= length()){
                return -1; 
            }
            if(index < 0){
                return -2;
            }
            if(isEmpty()){
                return -3; 
            }
            if(index == 0){
                Node<T> *temp = head; 
                head = head->getNext(); 
                delete temp; 
                return 1; 
            }
            int counter = 0; 
            Node<T> *current = head; 
            Node<T> *prev = NULL; 
            while(current->getNext() != NULL && index > counter){
                prev = current; 
                current = current->getNext(); 
                counter++; 
            }
            prev->setNext(current->getNext());
            delete current; 
            return 1; 
        }; 

        int getNth(int index){
            if(index < 0){
                return -1; 
            }
            if(index >= length()){
                return -2; 
            }
            int counter = 0; 
            Node<T> *current = head; 
            while(current->getNext() != NULL && index > counter){
                current = current->getNext(); 
                counter++; 
            }
            T item = current->getValue(); 
            return 1; 
        }; 

        // Tarea. Incluir complejidad computacional de cada función
        
        int count(T searchFor){
            /* Dado un elemento, devuelve el número de veces que el mismo aparece en la lista. */
            int counter = 0; 
            Node<T> *current = head;   
            while(current != NULL){
                if(current->getValue() == searchFor){
                    counter++; 
                }
                current = current->getNext(); 
            }
            return counter; 
        }; 

        void deleteList(){
            /* Eliminar la lista enlazada y liberar memoria de todos sus nodos. */
        }; 

        void sortedInsert(Node<T> * newNode){
            /* Dada una lista ordenada en orden creciente y un nodo, inserte el nodo en la posición ordenada correcta en la lista. */
            T addValue = newNode->getValue(); 
            int index = 0; 
            Node<T> *current = head;   
            while(current != NULL && current->getValue() < addValue){
                current = current->getNext(); 
                index++; 
            }
            insertItem(addValue, index); //Esto no va a funcionar si se tiene que agregar al final
            if(index == this->length()){
                append(addValue); 
            }
            std::cout << "Node was inserted" << std::endl; 
        }; 

        void removeDuplicates(){
            /* Toma una lista ordenada en orden creciente y elimina los nodos duplicados de la lista. Idealmente, la lista solo debería recorrerse una vez.*/
            Node<T> *current = head;  
            std::vector<int> atIndex;  
            int counter = 0; 
            while(current->getNext() != NULL){
                if(current->getValue() == (current->getNext())->getValue()){
                    atIndex.push_back(counter+1); 
                }
                current = current->getNext(); 
                counter++;  
            }
            for(int i = 0; i < atIndex.size(); i++){
                deleteItem(atIndex[i]-i); 
            }
        }; 

        void reverse(){
            /* Invertir orden de una lista enlazada. */
        }; 


        
};

#endif