#include <iostream>
#include <map>
using namespace std; 

int fibonacci(int n){
    if(n == 0){
        return 0; 
    }

    else if (n == 1){
        return 1; 
    }

    else{
        return fibonacci(n-1) + fibonacci(n-2); 
    }
}

//Función usando memorización :)
int fiboCool(int n, map<int, int> &results){
    if(n == 0){
        return 0; 
    }

    else if (n == 1){
        return 1; 
    }

    else{
        if(results.find(n) != results.end()){
            cout << "Usé el map" << endl; //debugging 10/10
            return results[n]; 
        }
        int ans = fibonacci(n-1) + fibonacci(n-2);
        results.insert(pair<int, int>(n, ans)); 
        return ans;  
    }
}

int main(){
    map<int, int> results; 
    int a = 4; 
    int b = 5; 
    int c = 6; 
    //Primera llamada
    cout << fiboCool(a, results) << endl; 
    cout << fiboCool(b, results) << endl; 
    cout << fiboCool(c, results) << endl; 
    //Segunda llamada
    cout << fiboCool(a, results) << endl; 
    cout << fiboCool(b, results) << endl; 
    cout << fiboCool(c, results) << endl; 
    return 0; 
}