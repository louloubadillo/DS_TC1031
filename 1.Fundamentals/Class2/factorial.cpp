#include <iostream> 
using namespace std; 

int factorial(int n){
    if(n<0){
        throw "illegal negative number"; 
    }

    else if(n==0){
        return 1; 
    }

    else{
        return n * factorial(n-1); 
    }
}

int main(){
    int ans; 
    int number; 
    cout << "Enter a number to compute factorial: " << endl; 
    cin >> number; 
    ans = factorial(number); 
    cout << "The factorial " << number << "! is: " << ans << endl; 
}