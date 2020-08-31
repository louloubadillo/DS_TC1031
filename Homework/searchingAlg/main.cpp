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
    DECLARE_TIMING(m1);
    DECLARE_TIMING(m2);
    DECLARE_TIMING(m3);
    DECLARE_TIMING(m4);
    DECLARE_TIMING(m5);
    for(int i=0; i<5; i++){
        cout << "Buscar número: " << test[i] << endl;
        //Repetir cada algoritmo 10 veces

        //Algoritmo 1: sequential() 
        cout << "Algoritmo 1" << endl; 
        for(int j = 0; j<10; j++){
            START_TIMING(m1);
            testing.sequential(test[i]);
            STOP_TIMING(m1);
            cout << "Prueba " << j+1 << endl; 
            SHOW_TIMING(m1, "Tiempo de ejecución"); 
        }

        //Algoritmo 2: frontMovement()
        cout << "Algoritmo 2" << endl; 
        for(int j = 0; j<10; j++){
            START_TIMING(m2);
            testing.frontMovement(test[i]); 
            STOP_TIMING(m2);
            cout << "Prueba " << j+1 << endl; 
            SHOW_TIMING(m2, "Tiempo de ejecución");
        }

        cout << "Algoritmo 3" << endl; 
        //Algoritmo 3: transpose()
        for(int j = 0; j<10; j++){
            START_TIMING(m3);
            testing.transpose(test[i]);
            STOP_TIMING(m3); 
            cout << "Prueba " << j+1 << endl; 
            SHOW_TIMING(m3, "Tiempo de ejecución");
        }
        
        //A partir de aquí tiene que estar ordenado
        testing.sortAlg(); 

        cout << "Algoritmo 4" << endl; 
        //Algoritmo 4: sortedSequential()
        for(int j = 0; j<10; j++){
            START_TIMING(m4);
            testing.sortedSequential(test[i]);
            STOP_TIMING(m4); 
            cout << "Prueba " << j+1 << endl; 
            SHOW_TIMING(m4, "Tiempo de ejecución");
        }
        
         cout << "Algoritmo 5" << endl;
        //Algoritmo 5: binarySearch()
        for(int j = 0; j<10; j++){
            START_TIMING(m5);
            testing.binarySearch(test[i]); 
            STOP_TIMING(m5);
            cout << "Prueba " << j+1 << endl; 
            SHOW_TIMING(m5, "Tiempo de ejecución");
        }

    }

    return 0; 
}