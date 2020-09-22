#include <iostream> 
using namespace std;

//Los templates te permiten crear funciones o clases genéricas que funcionan con cualquier tipo de dato
template <class T>
T getMax(T a, T b){
    return (a > b ? a : b); //a es mayor a b? si sí return a, si no return b
}

int main(){
    cout << getMax(5,6) << endl; 
    cout << getMax(8.56789,9.4567) << endl; 

    return 0; 
}