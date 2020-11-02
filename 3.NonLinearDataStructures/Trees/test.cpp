#include "bst.h"
#include <iostream>

int main(){
    BinarySearchTree<int> tree; 
    // tree.insertNode(8); 
    // tree.insertNode(5); 
    // tree.insertNode(10); 
    // tree.insertNode(5);
    // tree.insertNode(7);
    // tree.insertNode(2);
    // tree.insertNode(1);
    // tree.insertNode(3);

    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(1);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);

    tree.printTreeA();
    std::cout << "______________" << std::endl; 
    tree.printTreeB();

    return 0; 
}