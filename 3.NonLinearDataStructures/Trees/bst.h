#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

template <class T>
class BTreeNode{
    private: 
        T value; 
        BTreeNode<T> * left; 
        BTreeNode<T> * right;
        int depth; 

    public: 
        ~BTreeNode<T>() {}; 
        BTreeNode<T>() {}; 
        BTreeNode<T> (T val){
            value = val; 
            left = nullptr; 
            right = nullptr; 
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
        int size = 0;
    
    public: 
        ~BinarySearchTree<T>() {};
        BinarySearchTree<T>() {
            root = nullptr; 
            size++; 
        };

        int getSizeTree(){
            return size; 
        }

        BTreeNode<T>* find(T val){
            BTreeNode<T> *ptr = root; 
            while(ptr != nullptr){
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
            return nullptr; 
        };

        bool insertNode(T value){
            BTreeNode<T> *ptr = root;
            BTreeNode<T> *pre = nullptr;

            while(ptr != nullptr){
                if (ptr->getValue() == value)
                    return false;
                pre = ptr;
                ptr = ptr->getValue() > value ? ptr->getLeft() : ptr->getRight();
            }

            BTreeNode<T> *new_node = new BTreeNode<T>(value);

            if (pre == nullptr)
                root = new_node;
            else {
                if (pre->getValue() < value)
                    pre->setRight(new_node);
                else
                    pre->setLeft(new_node);            
            }
            size++; 
            return true;
        };

        BTreeNode<T>* sucessor(BTreeNode<T> *node){
            BTreeNode<T> *ptr = node->getRight(); 
            while(ptr->getLeft() != nullptr){
                ptr = ptr->getLeft(); 
            }
            return ptr; 
        };

        BTreeNode<T>* deleteNode(BTreeNode<T>* node, int key){
            if(node == nullptr) return node; 

            //Si el valor es menor que el del nodo, ir a subarbol izq
            if(key < node->getValue()){
                node->setLeft(deleteNode(node->getLeft(), key)); 
            }

            else if (key > node->getValue()){
                node->setRight(deleteNode(node->getRight(), key)); 
            }
            
            else{
                if(node->getLeft() == nullptr){
                    BTreeNode<T> *temp = node->getRight(); 
                    delete node; 
                    return temp; 
                }

                else if(node->getRight() == nullptr){
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

        void populateDepths()
        {
            populateDepthsRec(root);
        };

        int populateDepthsRec(BTreeNode<T>* node){
            if(node == nullptr)
                return 0; 
            else{
                int left = populateDepthsRec(node->getLeft); 
                int right = populateDepthsRec(node->getRight); 
                if(left>right){
                    node->depth = left + 1; 
                }
                node->depth = right + 1; 

                return node->depth;
            }
        }

        // Tarea: Diferentes Prints
        void printTreeA()
        {
            std::vector<bool> cols;
            printTreeARec(root, cols, true);
        }

        void printTreeARec(BTreeNode<T>* node, std::vector<bool>& cols, bool last)
        {
            if (node == nullptr) return;
            
            for (bool col : cols)
            {
                std::cout << (col ? "|   " : "    ");
            }

            std::cout << (last ? "└───" : "├───"); // <--- el nivel ya se acabo?
            std::cout << node->getValue() << std::endl;

            cols.push_back(!last);
            printTreeARec(node->getLeft(), cols, node->getRight() == nullptr);
            printTreeARec(node->getRight(), cols, true);
            cols.pop_back();
            
        };

       void printTreeB(){
           
           std::queue<BTreeNode<T>*> fifo;
           loadQueue(fifo);

           int level = 0;
           while (!fifo.empty())
           {
               int count = 1 << level++;
               for (int i = 0; i < count; i++)
               {
                   auto current = fifo.front(); 
                   fifo.pop();
                   std::cout << "  ";
                   if(current == nullptr)
                   {
                       std::cout << "-";
                   }
                   else
                   {
                       std::cout << current->getValue();
                   }

                   std::cout << "  ";
               }
               
               std::cout << std::endl;
           }
       };

       void loadQueue(std::queue<BTreeNode<T>*>& fifo)
       {
           std::queue<BTreeNode<T>*> helper;
           helper.push(root);
           while (!helper.empty())
           {
               auto current = helper.front();
               fifo.push(current);
               helper.pop();
               if (current == nullptr) continue;

               if (current->getLeft() == nullptr && current->getRight() == nullptr) continue;
               helper.push(current->getLeft());
               helper.push(current->getRight());
           }
       }

       void printTreeBRec(BTreeNode<T>* node, int offset){

            //Faltó implementar la manera en la que se incluyan las líneas. 
       }


       void printTreeC(){
           // Utiliza la misma implementación de printTreeB, pero falta implementar las líneas. 
       };


};

#endif