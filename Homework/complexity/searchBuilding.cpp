#include <iostream>
using namespace std;

template <size_t n, size_t m>
int searchHighestA(int (&matrix)[n][m]){
    int row = n-1;
    int col = 0; 
    int selected = matrix[row][col];
    while(row>0 && col<m-1){
        if(selected == 0){
            if(matrix[row-1][col] == 1){
                col += 1; 
            }
            else{
                row -= 1; 
            } 
        }
        else{
            col += 1; 
        }
    }
    return col; 
}

/*
template <size_t n, size_t m>
int binarySearch(int (&matrix)[n][m], int min, int max){
    int middle = (min+max)/2; 

}

template <size_t n, size_t m>
int searchHighestB(int (&matrix)[n][m], int min, int max){
    int min = 0; 
    int max = n-1; 
    int tallest = 0;  
    int middle = (min+max)/2; 
    
}
*/

int main(){
    int sample[5][6] = {  
        {1,1,1,0,1,1}, 
        {1,1,0,0,0,1},
        {0,1,0,0,0,1},
        {0,1,0,0,0,1},
        {0,0,0,0,0,1}
    };

    cout << searchHighestA(sample) << endl; 

    return 0; 
}