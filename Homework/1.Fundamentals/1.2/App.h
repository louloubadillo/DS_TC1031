#ifndef App_h 
#define App_h

#include <iostream>
#include <vector>
#include "Sorter.h"
#include "Searcher.h"

using namespace std;

class App{

    Sorter sorty; 
    Searcher searchy;
    int size; 
    int searchRounds; 
    int sortingAlgorithm;  

    public: 
    App() {}; 
    ~App() {};

    void menu(){
        cout << "Hey there, how many elements will the vector have?" << endl;  
        cin >> size; 
        searchy.generateRandom(size); 
        cout << "How many elements do you want to search?" << endl; 
        cin >> searchRounds; 
        for(int i = 0; i < searchRounds; i++){
            searchElement();
        }
    }

    void searchElement(){
        cout << "What element are we going to search?" << endl; 
        int e; 
        cin >> e; 
        cout << "What sorting algorithm would you like to use?" << endl;
        cout << "1. BubbleSort" << endl;
        cout << "2. InsertionSort" << endl;
        cout << "Any other number: QuickSort" << endl;
        cin >> sortingAlgorithm; 
        int s1 = searchy.sequential(e); 
        vector <int> sorted = sortVector(sortingAlgorithm);
        int s2 = searchy.binarySearch(sorted, e); 
        searchy.printElements(); 
        cout << "According to the sequential search, the element " << e << " is at index: " << s1 << endl; 
        printElements(sorted); 
        cout << "According to the binary search, the element " << e << " is at index: " << s2 << endl; 
    }

    vector <int> sortVector(int alg){
        vector<int> sorted(searchy.getVector());
        if( alg == 1){
            cout << "Using BubbleSort " << endl; 
            BubbleSort bubsort;
            bubsort.ordenaBurbuja(sorted); 
        }
        else if (alg == 2){
            cout << "Using InsertionSort " << endl; 
            InsertionSort inssort; 
            inssort.ordenaInsercion(sorted); 
        }
        else{
             cout << "Using QuickSort " << endl; 
            QuickSort quisort; 
            quisort.ordenaQuick(sorted); 
        }
        return sorted; 
    }

    void printElements(vector <int> arr){
        cout << "The sorted vector is: " << endl; 
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " "; 
        } 
        cout << endl; 
    }

}; 


#endif