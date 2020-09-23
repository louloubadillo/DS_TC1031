#include "linked_list.h"

int main(){
    LinkedList<int> list; 
    list.push(5); 
    list.push(4); 
    list.push(3); 
    list.push(2); 
    list.push(1); 
    list.print(); 
    list.append(6); 
    list.print(); 
    list.insertItem(9,3); 
    list.insertItem(10,0); 
    list.insertItem(9,20); 
    list.print(); 
    list.deleteItem(0); 
    list.print(); 
    list.deleteItem(3); 
    list.print(); 
    list.deleteItem(list.length()); 
    list.print(); 
    std::cout << list.length() << std::endl; 
    std::cout << list.getNth(list.length()) << std::endl; 
    return 0; 
}