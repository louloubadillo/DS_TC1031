#include <iostream>
#include "Search.cpp"
#include "myTimer.h"
using namespace std;


int main(){
    //5 números de prueba 
    int test[5] = {9,99,32,27,42}; 

    Search <int>testing; 

    //Generar números aleatorios
    testing.generateRandomInts(); 

    for(int i=0; i<5; i++){
        //Repetir cada algoritmo 10 veces

        //Algoritmo 1: sequential() 
        for(int j = 0; j<10; j++){
            testing.sequential(test[i]); 
        }
        //Algoritmo 2: frontMovement()
        for(int j = 0; j<10; j++){
            testing.frontMovement(test[i]); 
        }
        //Algoritmo 3: transpose()
        for(int j = 0; j<10; j++){
            testing.transpose(test[i]); 
        }
        //A partir de aquí tiene que estar ordenado
        testing.sortAlg(); 
        //Algoritmo 4: sortedSequential()
        for(int j = 0; j<10; j++){
            testing.sortedSequential(test[i]); 
        }
        //Algoritmo 5: binarySearch()
        for(int j = 0; j<10; j++){
            testing.binarySearch(test[i]); 
        }

    }

    return 0; 
}