#include <iostream> 
using namespace std;

/*Programe un algoritmo recursivo que permita sumar los dígitos de un número*/

int sumDigits(int n){  
    if(n==0){
        return 0;
    }
    return n%10 + sumDigits(n/10); 
}

int main(){
    cout << sumDigits(123) << endl; //test :)
    return 0; 
}