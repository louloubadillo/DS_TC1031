#include <iostream>
#include "Search.cpp"
using namespace std;


int main(){
    int test1 = 9; 
    int test2 = 99; 
    int test3 = 32; 
    int test4 = 27; 
    int test5 = 42; 
    Search <int>testing; 
    testing.generateRandomInts(); 
    cout << testing.sequential(test1) << endl;
    testing.printElements(); 
    cout << testing.transpose(test1) << endl;
    testing.printElements();  
    cout << testing.frontMovement(test1) << endl; 
    testing.printElements(); 
    
    return 0; 
}