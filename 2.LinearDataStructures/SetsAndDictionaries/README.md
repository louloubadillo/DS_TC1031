# Conjuntos y Diccionarios

## Hashing 
- Una función hash es aquella que permite obtener una representación compacta de una entrada.
- La salida generalmente es de tamaño fijo. 
- En este tipo de función, generalmente no se puede regresar de la salida a la entrada.
  
### Usos
1. Verificar que algo no ha cambiado (integridad de los datos).
2. Decidir la posición de los datos en un arreglo:
   - Módulo: El residuo de la división de los datos, entre el tamaño del arreglo.
   - Plegamiento: Se toman algunos números a partir de los datos, se suman y se toman los n dígitos menos significativos
   - Truncamiento: Se recorta el dato y se toma el número como posición.
  
### Colisiones
- Si una función hash produce la misma dirección para dos valores diferentes, se considera que tiene una colisión.
- Entre más pequeño sea el espacio de salida, es más probable que ocurra.
- Hay distintas soluciones: 
  - Prueba lineal: Se recorre el arreglo de forma secuencial hasta encontrar un espacio para insertar, o hasta detectar que el arreglo está lleno. 
  - Encadenamiento: La dirección obtenida por la función hash apunta a una estructura lineal y el elemento se inserta al final de la misma. 

## Conjuntos 
- Matemáticamente, son una colección de objetos. 
- Como estructura de datos, nos permite guardar datos únicos (sin repetir). 
- Las operaciones de inserción, eliminación y búsqueda usan hashes, por lo que la complejidad es $O(1)$. Pero los datos no están ordenados.
<br>   

En C++STL: 
```cpp
class template
std::set
```

## Diccionarios
- Estructura de datos que puede guardar pares de llaves y objetos. 
- A las llaves se les aplica el hash para determinar la posición dentro del arreglo. 
- Las llaves son únicas, aunque aplican las mismas técnicas de colisiones que las tablas de hash. 
- <br>   

En C++STL: 
```cpp
class template
std::map
```