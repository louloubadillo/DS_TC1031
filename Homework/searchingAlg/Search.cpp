#include <iostream>
#include <cstdio>     
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template<typename T>
class Search{
    vector<T> elements;
    public: 
        Search() = default; 
        void generateRandomInts(){
            srand(time(0));
            int quantity = 100000; 
            for (int i = 0; i < quantity; i++){
                int e = rand() % 100 + 1;
                elements.push_back(e);
            }
            /* Print
            for (int i = 0; i < elements.size(); i++){
                cout << elements[i] << " "; 
            } */
        } 
        int sequential (T element){
            for(int i = 0; i<elements.size(); i++){
                if(elements[i] == element){
                    return i; 
                }
            }
            return -1; 
        }
        int frontMovement(T element); 
        int transpose(T element); 
        int sortedSequential(T element); 
        int binarySearch(T element); 
}; 