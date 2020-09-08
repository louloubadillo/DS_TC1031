#include <iostream>
using namespace std;

/*Este algoritmo es O(m+n) porque en el peor de los casos tiene que recorrer toda la matriz en n (hacia arriba) y luego en m (hacia la derecha) */
template <size_t n, size_t m>
int searchHighestA(int (&matrix)[n][m]){
    int max = n-1;
    int max_idx = 0;

    for (int col = 0; col < m; col++){
        while (max != 0 && matrix[max-1][col] == 0){
            max_idx = col;
            max--;
        }

        if (max == 0){
            break;
        }
    }
    return max_idx;
}

/*Este algoritmo es O(mlogn) */
template <size_t n, size_t m>
int binarySearch(int (&matrix)[n][m], int col, int min, int max){
    if (min == max){
        return min;
    }

    int middle = (min + max) / 2;
    if (matrix[middle][col] == 0){
        if (middle == 0){
            return 0;
        }

        if (matrix[middle - 1][col] == 1){
            return middle;
        }

        return binarySearch(matrix, col, min, middle - 1);
    }
    else{
        return binarySearch(matrix, col, middle + 1, max);
    }
}

template <size_t n, size_t m>
int getHeight(int (&matrix)[n][m], int col){
    return n - binarySearch(matrix, col, 0, n);
}

template <size_t n, size_t m>
int searchHighestB(int (&matrix)[n][m]){
    int highestIndex = 0;
    int highest = getHeight(matrix, 0);
    for (int i = 1; i < m; i++){
        int search = getHeight(matrix, i);
        if (search > highest){
            highest = search;
            highestIndex = i;
        }
    }

    return highestIndex;
}

int main(){
    int sample[6][8] = {
        {1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1}
    };

    cout <<"Algorithm 1 (O(n+m)): The tallest building is at index: " << searchHighestA(sample) << endl; 
    cout <<"Algorithm 2 (O(mlogn)): The tallest building is at index: " << searchHighestB(sample) << endl; 
    return 0; 
}