#ifndef _BST_H
#define _BST_H

#include <iostream>

template <class T>
class BTreeNode{
    private: 
        T value; 
        BTreeNode<T> * left; 
        BTreeNode<T> * right; 

    public: 
        ~BTreeNode<T>() {}; 
        BTreeNode<T>() {}; 
        BTreeNode<T> (T val){
            value = val; 
            left = NULL; 
            right = NULL; 
        };
        BTreeNode<T> (T val, BTreeNode<T> *_left, BTreeNode<T> *_right ){
            value = val; 
            left = _left; 
            right = _right; 
        }; 

        T getValue(){
            return value; 
        };

        BTreeNode<T> *getLeft(){
            return left; 
        };

        BTreeNode<T> *getRight(){
            return right; 
        };

        void setValue(T val){
            value = val; 
        };

        void setLeft(BTreeNode<T> *node){
            left = node; 
        }; 

        void setRight(BTreeNode<T> *node){
            right = node; 
        }; 
}; 

template <class T>
class BinarySearchTree{
    private: 
        BTreeNode<T> *root; 
    
    public: 
        ~BinarySearchTree<T>() {};
        BinarySearchTree<T>() {
            root = NULL; 
        };

        BTreeNode<T>* find(T val){
            BTreeNode<T> *ptr = root; 
            while(ptr != NULL){
                if(ptr->getValue() == val){
                    return ptr; 
                }
                if(ptr->getValue() > val){
                    ptr = ptr->getLeft(); 
                }
                else{
                    ptr = ptr->getRight(); 
                }
            }
            return NULL; 
        };

        bool insertNode(T value){
            BTreeNode<T> *ptr = root;
            BTreeNode<T> *pre = NULL;

            while(ptr != NULL)
            {
                if (ptr->getValue() == value)
                    return false;
                pre = ptr;
                ptr = ptr->getValue() > value ? ptr->get_left() : ptr->get_right();
            }

            BTreeNode<T> *new_node = new BTreeNode<T>(value);

            if (pre == NULL)
                root = new_node;
            else
            {
                if (pre->getValue() < value)
                    pre->setRight(new_node);
                else
                    pre->setLeft(new_node);            
            }
            return true;
        };

        BTreeNode<T>* sucessor(BTreeNode<T> *node){
            BTreeNode<T> *ptr = node->getRight(); 
            while(ptr->getLeft() != NULL){
                ptr = ptr->getLeft(); 
            }
            return ptr; 
        };

        BTreeNode<T>* deleteNode(BTreeNode<T>* node, int key){
            if(node == NULL) return node; 

            //Si el valor es menor que el del nodo, ir a subarbol izq
            if(key < node->getValue()){
                node->setLeft(deleteNode(node->getLeft(), key)); 
            }

            else if (key > node->getValue()){
                node->setRight(deleteNode(node->getRight(), key)); 
            }
            
            else{
                if(node->getLeft() == NULL){
                    BTreeNode<T> *temp = node->getRight(); 
                    delete node; 
                    return temp; 
                }

                else if(node->getRight() == NULL){
                    BTreeNode<T> *temp = node->getLeft(); 
                    delete node; 
                    return temp; 
                }

                BTreeNode<T> * temp = sucessor(node); 
                node->setValue(temp->getValue()); 
                node->setRight(deleteNode(node->getRight(), temp->getValue()));
            }
            return node; 
        };

        void deleteNode(T val){
            root = deleteNode(root, val); 
        };

        bool isBrother(){
            //Si un nodo es hermano de otro nodo 
        };

        







};

#endif