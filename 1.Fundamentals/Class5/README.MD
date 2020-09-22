# Clase 5: Algoritmos de Búsqueda

# Búsqueda
Si se requiere tener acceso a los elementos dentro de una estructura de datos, es necesario tener un algoritmo de búsqueda. <br>
Por convención, los algoritmos de búsqueda regresan la posición del valor a encontrar, o -1 si el valor no se encuentra. <br>
Los algoritmos de búsqueda son aplicables a todas las estructuras de datos. Sin embargo, la implementación varía por estructura. 

## Búsqueda Secuencial 
- Aplicable a todos los arreglos
- Su implementación es trivial 
- Se busca posición por posición hasta que se encuentre el elemento o se acabe el arreglo
  
¿Qué recursos necesita en tiempo y memoria? 
- Mejor caso: Ω(1)
- Peor caso: O(n)

### Búsqueda Secuencial Ordenada (v1)
- La primera mejora requiere de ordenar el arreglo. (No trivial)
- Al tener un arreglo ordenado, se puede mejorar el tiempo al poner un límite superior
- Si el siguiente elemento del arreglo es mayor que el que estamos buscando, se termina la búsqueda

¿Qué recursos necesita en tiempo y memoria? 
- Mejor caso: Ω(1)
- Peor caso: O(n)
  
### Búsqueda Secuencial Ordenada (v2)
- Buscar el valor y usar un paso 
- Si el valor es más grande, tenemos que buscar en el siguiente bloque
- Si el valor es menor, se encuentra en los elementos anteriores
- ¿Qué paso sería adecuado usar? -> Ir dividiendo el paso a la mitad con cada iteración -> Por lo que es un algoritmo recursivo (se hace el mismo método pero cambiando el "tamaño" del arreglo en el que buscamos)

¿Qué recursos necesita en tiempo y memoria? 
- Mejor caso: Ω(1)
- Peor caso: Es más eficiente O(1/2 * n), pero debido a que las constantes se ignoran, sigue siendo O(n)

### Búsqueda Binaria
- Llevar la búsqueda secuencial ordenada a su máximo extremo
- Cada paso elimina la mitad del arreglo
- Ejemplo clásico del paradigma: "Divide y vencerás"
- Se repite recursivamente con la mitad donde esperamos que se encuentre el valor
- El algoritmo termina cuando el arreglo es de tamaño 0, o el valor se encuentra

¿Qué recursos necesita en tiempo y memoria? 
- Mejor caso: Ω(1)
- Peor caso: O(log n)
