#include <iostream> 
using namespace std;

int sumaIterativa(int n){
    int suma = 0; 
    if (n < 0){
        cout << "Error: Número negativo" << endl; 
        return -1; 
    }
    for(int i = 1; i<=n; i++){
        suma += i; 
    }
    return suma; 
}

int sumaRecursiva(int n){
    if (n < 0){
        cout << "Error: Número negativo" << endl; 
        return -1; 
    }
    else if( n == 0){
        return 0; 
    }
    return n + sumaRecursiva(n-1); 
}

int sumaDirecta(int n){
    if (n < 0){
        cout << "Error: Número negativo" << endl; 
        return -1; 
    } 
    return (0.5)*n*(1+n); 
}

int main(){

    // Pruebas
    int example1 = 100; 
    int example2 = 1; 
    int example3 = 0; 
    int example4 = -2; 
    cout << "Prueba 1: n = 100" << endl; 
    cout << "Suma Iterativa: " << sumaIterativa(example1) << endl; 
    cout << "Suma Recursiva: " << sumaRecursiva(example1) << endl; 
    cout << "Suma Directa: " << sumaDirecta(example1) << endl;
    cout << "Prueba 2: n = 1" << endl;
    cout << "Suma Iterativa: " << sumaIterativa(example2) << endl; 
    cout << "Suma Recursiva: " << sumaRecursiva(example2) << endl; 
    cout << "Suma Directa: " << sumaDirecta(example2) << endl;
    cout << "Prueba 3: n = 0" << endl;
    cout << "Suma Iterativa: " << sumaIterativa(example3) << endl; 
    cout << "Suma Recursiva: " << sumaRecursiva(example3) << endl; 
    cout << "Suma Directa: " << sumaDirecta(example3) << endl;
    cout << "Prueba 4: n = -2" << endl;
    cout << "Suma Iterativa: " << sumaIterativa(example4) << endl; 
    cout << "Suma Recursiva: " << sumaRecursiva(example4) << endl; 
    cout << "Suma Directa: " << sumaDirecta(example4) << endl;
    return 0; 
}