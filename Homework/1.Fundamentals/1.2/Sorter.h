#ifndef Sorter_h 
#define Sorter_h

#include <iostream>
#include <vector>

class Sorter {
    public: 
    Sorter() {}; 
    ~Sorter() {}; 

    void swap(int i, int j, std::vector<int> &arr){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    };
};

class BubbleSort : public Sorter {

    public: 
    BubbleSort() {}; 
    ~BubbleSort() {}; 

    void ordenaBurbuja(std::vector<int> &arr){
        bool swapped = false; 
        for (size_t i = 0; i < arr.size(); i++) {
            swapped = true; 
             for (size_t j = 0; j < arr.size() - i-1; j++){
                if (arr[j] > arr[j+1]){
                    Sorter::swap(j,j+1,arr); 
                    swapped = false;
                }
            }
                
        }   
    }; 
};

class InsertionSort : public Sorter {
        public: 
        InsertionSort() {}; 
        ~InsertionSort() {}; 

        void ordenaInsercion(std::vector<int> &arr){
            int key; 
            for(size_t i = 1; i < arr.size(); i++){
                key = arr[i]; 
                int j = i-1; 
                while(j >= 0 && arr[j] > key){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key; 
            }
        }
};

class QuickSort : public Sorter{
    public: 
    QuickSort() {}; 
    ~QuickSort() {};

    void ordenaQuick(std::vector<int> &arr){
        quicksort(arr,0,arr.size()-1); 
    }

    void quicksort(std::vector<int> &arr, int low, int high){
        if (low < high){
            int piv = partition(arr, low, high); 
            quicksort(arr,low,piv-1); 
            quicksort(arr, piv+1, high); 
        }
    } 

    int partition(std::vector<int> &arr, int low, int high){
        int pivot = arr[high]; 
        int i = low - 1; 

        for(int j = low; j <= high-1; j++){
            if(arr[j] < pivot){
                i++; 
                Sorter::swap(i,j,arr); 
            }
        }
        Sorter::swap(i+1,high, arr); 
        return (i+1); 
    }
};

#endif