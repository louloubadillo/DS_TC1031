#include "linked_list.h"
#include <iostream>

int main(){
    LinkedList<int> list; 
    list.push(5);
    list.push(5);
    list.push(4);
    list.push(4); 
    list.push(4);
    list.push(3); 
    list.push(3); 
    list.push(2); 
    list.push(2); 
    list.push(1);
    list.push(1);
    list.push(1);
    list.push(1);
    list.push(1); 
    list.print(); 
    list.count(4); 
    list.removeDuplicates(); 
    list.print(); 
    Node<int> newNode(3, NULL); 
    list.sortedInsert(&newNode); 
    list.print(); 
    list.reverse(); 
    list.print(); 
    list.deleteList(); 
    list.print(); 
    return 0; 
}