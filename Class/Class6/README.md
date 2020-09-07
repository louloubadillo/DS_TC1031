# Clase 6: Algoritmos de Ordenamiento

# Ordenamiento 
- Permite darle un orden específico a una estructura de datos.
- Facilita la búsqueda, agregar valores, encontrar mínimos y máximos, además de optimizar tiempos de proceso.
- No existe un algoritmo que sea mejor que los demás en todos los casos, siempre es necesario analizar el tipo de problema y las restricciones. 

## Selection Sort
- Es uno de los métodos más simples que existen. 
- También es uno de los más ineficientes.
- Se trata de seleccionar el menor (o mayor) elemento en cada paso y colocarlo en la parte izquierda (o derecha) del arreglo, disminuir uno la longityd y repetir el proceso. 

¿Qué recursos necesita en tiempo? 
- Peor caso: $O(n^2)$
- Mejor caso: $Ω(n^2)$
  
## Bubble Sort
- Muy simple pero muy ineficiente
- Menos ineficiente si se tiene una bandera de no cambio
- La idea es que los elementos más chicos "floten" hacia la superficie. 
- Para lograrlo, se comparan los elementos de dos en dos, yendo hacia la derecha. 
- Si el elemento de la derecha es menor que el de la izquierda, se intercambian. 
- Al final de la iteración, el elemento más grande es empujado hasta el final. 
- El proceso se repite con un elemento menos. 

¿Qué recursos necesita en tiempo? 
- Peor caso: $O(n^2)$
- Mejor caso: $Ω(n)$

## Insertion Sort
- En cada paso, el elemento en cuestión queda colocando en el lugar correcto del arreglo, de acuerdo a todos los elementos que están antes que él. 
- Cada elemento se compara con los que están antes: 
  - Si es mayor, ahí se queda
  - Si es menor, se mueve uno hacia la izquierda y se repite la operación hasta llegar a su posición correcta

¿Qué recursos necesita en tiempo? 
- Peor caso: $O(n^2)$
- Mejor caso: $Ω(n)$

## Merge Sort
- Sigue la idea de "Divide y vencerás"
- Algoritmo muy eficiente 
- Trabaja con tres pasos: 
  - Dividir el arreglo desordenado en dos partes
  - Ordenar cada una de las partes recursivamente
  - Combina (merge) las partes resultantes ordenadas
  
¿Qué recursos necesita en tiempo? 
- Peor caso: $O(n log(n))$
- Mejor caso: $O(n log(n))$
  
## Quick Sort
- De los algoritmos más utilizados. 
- Es uno de los algoritmos llamados "Divide y vencerás"
- Se puede programar elegantemente de forma recursiva. 
- La estructura es: 
  - Requiere utilizar un "pivote"
  - Particionar alrededor de él 
- Existen diferentes maneras de seleccionar el elemento pivote: 
    - Usar el primer elemento
    - Usar el último elemento
    - Escogerlo aleatoriamente
    - Seleccionar la mediana 

¿Qué recursos necesita en tiempo? 
- Peor caso: $O(n^2)$ 
  - En promedio es: $O(n log(n))$
- Mejor caso: $O(n log(n))$