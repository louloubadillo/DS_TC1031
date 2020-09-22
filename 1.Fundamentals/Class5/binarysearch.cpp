#include <iostream> 
using namespace std;

int binarySearch(int arr[], int first, int last, int k){
    int index; 
    if(last < first){
        index = -1; 
    }
    else{
        int middle = (first+last)/2; 
        if(k == arr[middle]){
            index = middle; 
        }
        else if (k < arr[middle]){
            index = binarySearch(arr, first,middle-1, k); 
        }
        else{
            index = binarySearch(arr, middle+1, last, k);
        }
    }
    return index; 
}