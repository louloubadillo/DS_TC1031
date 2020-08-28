#include <iostream> 
using namespace std;

int sumaIterativa(int n){
    int suma; 
    for(int i = n; i>0; i--){
        suma += i; 
    }
    return suma; 
}

int sumaRecursiva(int n){
    if (n < 0){
        return 0; 
    }
    return n + sumaRecursiva(n-1); 
}

int sumaDirecta(int n){
    return (n/2)*(1+n); 
}

int main(){
    int example = 100; 
    cout << "Suma Iterativa: " << sumaIterativa(example) << endl; 
    cout << "Suma Recursiva: " << sumaRecursiva(example) << endl; 
    cout << "Suma Recursiva: " << sumaDirecta(example) << endl;
    return 0; 
}