#include <iostream> 
#include <string>
using namespace std;

/*Implemente una función recursiva que determine si una 
cadena de caracteres es un palíndromo. */

bool isPalindrome(string s) {
    int size = s.size();

    if(size == 0 || size == 1) {
        return true; 
    }

    if(s[0] == s[size -1]) {
        return isPalindrome(s.substr(1,size-2));
    }

    return false; 
}

int main(){
    cout << false << endl; //omg whaat? 
    cout << isPalindrome("ana") << endl; 
    cout << isPalindrome("hello") << endl; 
    return 0; 
}