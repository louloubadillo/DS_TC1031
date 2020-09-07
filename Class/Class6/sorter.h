#ifndef sorter_h 
#define sorter_h

#include <iostream>
#include <vector>


template <typename T>
class Sorter {
    public: 
    Sorter() {}; //Lo mismo a = default
    ~Sorter() {}; 

    void swap(int i, int j, std::vector<T> &arr){
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};

}; 

template <typename T>
class SelectionSort : public Sorter<T> {

    public: 
    SelectionSort() {}; 
    ~SelectionSort() {}; 

    void sort(std::vector<T> &arr){
        for (size_t i = 0; i < arr.size() - 1; i++){
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++){
                if (arr[j] < arr[min])
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }        
    }; 

};

template <typename T>
class BubbleSort : public Sorter<T> {

    public: 
    BubbleSort() {}; 
    ~BubbleSort() {}; 

    void sort(std::vector<T> &arr){
        bool swapped = false; 
        for (size_t i = 0; i < arr.size(); i++) {
            swapped = true; 
             for (size_t j = 0; j < arr.size() - i-1; j++){
                if (arr[j] > arr[j+1]){
                    Sorter<T>::swap(j,j+1,arr); 
                    swapped = false;
                }
            }
                
        }   
    }; 

};

template <typename T>
class InsertionSort : public Sorter<T> {
        public: 
        InsertionSort() {}; 
        ~InsertionSort() {}; 

        void sort(std::vector<T> &arr){
            T key; 
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

template <typename T>
class MergeSort : public Sorter<T> {
        public: 
        MergeSort() {}; 
        ~MergeSort() {}; 

        void sort(std::vector<T> &arr){
            std::vector<T> helper;
            helper.reserve(arr.size());
            mergesort(arr, helper, 0, arr.size() - 1);
        }

        void mergesort(std::vector <T> &arr, std::vector <T> &helper, int start, int end){
            if (start < end){
                int med = (start + end) / 2;
                mergesort(arr, helper, start, med);
                mergesort(arr, helper, med + 1, end);
                merge(arr, helper, start, med + 1, end);
            }  
        }

        void merge(std::vector<T>& arr, std::vector<T>& helper, int start_a, int start_b, int end_b){
            int end_a = start_b - 1;        // End of first half
            int k = start_a;                // Next Position
            int num = end_b - start_a + 1;  // Amount of elements

            while (start_a <= end_a && start_b <= end_b) {
                if (arr[start_a] <= arr[start_b]) {
                    helper[k++] = arr[start_a++];
                }
                else {
                    helper[k++] = arr[start_b++];
                }
            }

            while (start_a <= end_a){
                helper[k++] = arr[start_a++];
            }

            while (start_b <= end_b){
                helper[k++] = arr[start_b++];
            }

            for ( int i = 0; i < num; i++, end_b--){
                arr[end_b] = helper[end_b];
            }
                    
        }
            
}; 
#endif