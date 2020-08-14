#include <iostream> 
using namespace std;

/*Programe una función recursiva que devuelva el máximo común divisor de dos números enteros
utilizando el algoritmo de Euclides. */

int getMCD(int m, int n){
    if(m<n){
        int temp = m; 
        m = n; 
        n = temp; 
    }
    int r = m%n; 
    if(r == 0){
        return n;
    }
    return getMCD(n, r); 
}

int main(){
    cout << getMCD(120,770) << endl; //Ejemplo

    return 0; 
}
