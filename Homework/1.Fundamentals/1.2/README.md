# Actividad 1.2: Algoritmos de Búsqueda y Ordenamiento

Realiza una aplicación en C++ en forma individual,  en donde dado n el tamaño de un vector<int> este se llene de manera aleatoria. <br>

La aplicación deberá solicitar al usuario la cantidad de búsquedas que desea, y por cada búsqueda deberá de solicitar el número que desea buscar y desplegará el índice donde se encuentra localizado o -1 en caso de que no se encuentre, la búsqueda deberá realizarla en ambos métodos (secuencial y binario). <br>
Además, el programa deberá pedirle al usuario que seleccione qué algoritmo de ordenamiento (insertion sort, bubblesort o quicksort) desea utilizar para ordenar la lista antes de ejecutar la búsqueda binaria. 

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. 

El programa debe implementar entre otras las siguientes funciones:

## ordenaInsercion	
- Descripción: Ordene en forma ascendente los datos con el método de Inserción
- Entrada: Un vector<int> con los n numeros
- Salida: Ninguna
- Precondición: El vector<int> debe contener los n números
- Postcondición: El vector<int> contendrá los datos ya ordenados

## ordenaBurbuja	
- Descripción: Ordene en forma ascendentelos datos con el método de Burbuja
- Entrada: Un vector<int> con los n numeros
- Salida: Nada
- Precondición: El vector<int> debe contener los n números
- Postcondición: El vector<int> contendrá los datos ya ordenados
  
## ordenaQuick	
- Descripción: Ordene en forma ascendente los datos con el método de Quicksort
- Entrada: Un vector<int> con los n numeros
- Salida: Nada
- Precondición: El vector<int> debe contener los n números
- Postcondición: El vector<int> contendrá los datos ya ordenados

## busqSecuencial	
- Descripción: Buscar con la busqueda secuencial un dato entero dentro del vector.
- Entrada: El vector <int> del espacio de búsqueda y el dato entero que se desea buscar.
- Salida: El índice donde se encuentra el dato o -1 en caso de que no se localice.
- Precondición: El vector<int> debe contener los n números
- Postcondición: Ninguna
  

## busqBinaria	
- Descripción: Buscar con la busqueda binaria un dato entero dentro del vector.
- Entrada: El vector <int> ordenado del espacio de búsqueda y el dato entero que se desea buscar.
- Salida: El índice donde se encuentra el dato o -1 en caso de que no se localice.
- Precondición: El vector<int> debe contener los n números ordenados en forma ascenedente
- Postcondición: Ninguna