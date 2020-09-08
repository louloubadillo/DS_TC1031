#ifndef Searcher_h 
#define Searcher_h

#include <iostream>
#include <vector>
#include <cstdio>     
#include <cstdlib>
#include <ctime>

using namespace std; 

class Searcher{

    vector<int> elements;

    public: 
    Searcher() {}; 
    ~Searcher() {};

    vector<int> getVector(){
        return elements; 
    }

    void generateRandom(int size){
        srand(time(0)); 
        for (int i = 0; i < size; i++){
            int e = rand() % 10 + 1; 
            elements.push_back(e);
        }
    }

    void printElements(){
        cout << "The vector is: " << endl; 
        for (int i = 0; i < elements.size(); i++){
            cout << elements[i] << " "; 
        } 
        cout << endl; 
    }

    int sequential (int element){
        for(int i = 0; i<elements.size(); i++){
            if(elements[i] == element){
                return i; 
            }
        }
        return -1; 
    } 

    int binarySearchRec(vector<int> arr, int element, int min, int max){
            int middle = (min + max)/2; 
            if(max < min){
                return -1; 
            }
            if(element == arr[middle]){
                return middle; 
            }
            else if (element < arr[middle]){
                return binarySearchRec(arr,element, min, middle-1); 
            }
            else{
                return binarySearchRec( arr, element, middle+1, max); 
            }
        } 

        int binarySearch(vector<int> arr, int element){
            return binarySearchRec( arr, element, 0, elements.size()); 
        }
}; 


#endif