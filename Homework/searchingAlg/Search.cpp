#include <iostream>
#include <cstdio>     
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class Search{

    vector<T> elements;

    public: 

        Search() = default; 

        vector <T> getElements(){
            return elements; 
        }

        void printElements(){
            for (int i = 0; i < elements.size(); i++){
                cout << elements[i] << " "; 
            } 
            cout << endl; 
        }

        void generateRandomInts(){
            srand(time(0));
            int quantity = 10;//00000; 
            for (int i = 0; i < quantity; i++){
                int e = rand() % 10 + 1; //cambiar a 100
                elements.push_back(e);
            }
        } 

        int sequential (T element){
            for(int i = 0; i<elements.size(); i++){
                if(elements[i] == element){
                    return i; 
                }
            }
            return -1; 
        }

        int frontMovement(T element){
            for(int i = 0; i<elements.size(); i++){
                if(elements[i] == element){
                    elements.erase(elements.begin()+i); 
                    elements.insert(elements.begin(), element); 
                    return i; 
                }
            }
            return -1; 
        }

        int transpose(T element){
            for(int i = 0; i<elements.size(); i++){
                if(elements[i] == element){
                    if(i != 0){
                        elements [i] = elements[i-1]; 
                        elements[i-1] = element;
                    }
                    return i; 
                }
            }
            return -1;
        } 

        vector <T> sortVector(){
            vector<T> saved(elements);
            sort(elements.begin(), elements.end()); 
            vector <T> sorted = elements; 
            elements = saved;
            return sorted; 
        }
    
        //Tiene que estar sorted, pero lo voy a hacer fuera del método para que no afecte el tiempo de ejecución
        int sortedSequential(T element){
            return this->sequential(element); 
        } 

        //Tiene que estar sorted, pero lo voy a hacer fuera del método para que no afecte el tiempo de ejecución
        int binarySearch(vector <T> v, T element, int min, int max){
            int middle = (min + max)/2; 
            if(max < min){
                return -1; 
            }
            if(element == v[middle]){
                return middle; 
            }
            else if (element < v[middle]){
                return binarySearch(v, element, min, middle-1); 
            }
            else{
                return binarySearch(v, element, middle+1, max); 
            }
        } 
}; 