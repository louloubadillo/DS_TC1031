# Clase 6: Algoritmos de Ordenamiento

# Ordenamiento 
- Permite darle un orden específico a una estructura de datos.
- Facilita la búsqueda, agregar valores, encontrar mínimos y máximos, además de optimizar tiempos de proceso.
- No existe un algoritmo que sea mejor que los demás en todos los casos, siempre es necesario analizar el tipo de problema y las restricciones. 

## Selection Sort
- Es uno de los métodos más simples que existen. 
- También es uno de los más ineficientes.
- Se trata de seleccionar el menor (o mayor) elemento en cada paso y colocarlo en la parte izquierda (o derecha) del arreglo, disminuir uno la longityd y repetir el proceso. 

¿Qué recursos necesita en tiempo y memoria? 
- Peor caso: $O(n^2)$
  
## Bubble Sort
- Muy simple pero muy ineficiente
- Menos ineficiente si se tiene una bandera de no cambio
- La idea es que los elementos más chicos "floten" hacia la superficie. 
- Para lograrlo, se comparan los elementos de dos en dos, yendo hacia la derecha. 
- Si el elemento de la derecha es menor que el de la izquierda, se intercambian. 
- Al final de la iteración, el elemento más grande es empujado hasta el final. 
- El proceso se repite con un elemento menos. 
## Insertion Sort
## Merge Sort
## Quick Sort