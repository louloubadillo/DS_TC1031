#include <iostream>
using namespace std; 

/* Hacer una clase Calculator
input: dos números
output: suma, resta, multiplicación y división
Tenemos que usar templates */

template <class T> //T podría tener cualquier nombre
class Calculator{
    private: 
    T a,b; 
    public: 
    Calculator(T a, T b){
        this->a = a; 
        this->b = b; 
    }; 

    T add(){return a+b;};
    T substract(){ return a-b;};
    T multiply(){return a*b;};
    T divide(){return a/b;};

    void displayResult(){
        cout << "Los números son: " << a << " y " << b << endl; 
        cout << "Suma: " << add() << endl;
        cout << "Resta: " << substract() << endl;
        cout << "Multiplica: " << multiply() << endl; 
        cout << "Divide: " << divide() << endl;
    }
}; 

int main(){
    Calculator <int> calc_i(42,24); //Se especifica el tipo de dato que se va a usar entre los <>
    Calculator <double> calc_d(42.24, 24.42); 
    calc_i.displayResult(); 
    calc_d.displayResult(); 
    return 0; 
}