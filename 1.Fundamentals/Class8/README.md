# Apuntadores y Memoria 
# Apuntadores
## ¿Qué son? 
- Un apuntador guarda un referencia (dirección de memoria) a otro valor. 
- No almacena el valor en sí, sino es una referencia indirecta al mismo.

## Declaración en C++
``` cpp
tipo *nombre_apuntador
``` 
Ejemplo: 
``` cpp
int *P; 
char *s; 
Rect *rect; 
SelectionSort<float> *selSort; 
``` 

## Operador de indirección (*)
Accede al valor apuntado. 
``` cpp
int *p; 
*p = 5; 
int var = *p; //var toma valor 5
``` 

## Operador de dirección (&)
Genera una referencia (apuntador) a la variable.
``` cpp
int var = 42; 
int* p; 
p = &var; 
``` 
## Aritmética de apuntadores
- Se puede realizar un conjunto limitado de operaciones aritméticas con punteros. Un puntero puede ser: 
  - Incrementado (++) 
  - Decrementado (--)
  - Adicionar un número entero a un puntero (+ o +=)
  - Substraer un número entero a un puntero (- o -=)
- Esta aritmética no tiene lógica a menos de que se use en un arreglo. (Porque los datos se almacenan de manera continua en la memoria).
- Los punteros contienen direcciones. Sumar dos direcciones no tiene sentido, porque no tienes idea qué está almacenado en esa dirección. 
- Restar dos direcciones te permite calcular el desplazamiento entre estas dos direcciones. 

# Memoria

## Asignación de memoria
Existen dos tipos de asignación de memoria en C++: 
- Automática o local (Stack)
    - Las variables de denominan "locales" porque su vida útil está ligada al scope (ámbito) en la que se declaran. 
    - Siempre que se ejecuta la función, se asignan sus variables locales. 
    - Cuando el scope termina, sus locales se liberan. 
    ``` cpp
    int var = 42; 
    ``` 
- Dinámica (Heap)
  - El programador solicita explícitamente la asignación de memoria de un tamaño particular. 
  - El bloque continúa asignado hasta que el programador solicita explícitamente que se libere. 
  - Nada sucede de manera automática, por lo tanto, el programador tiene un control mucho mayor de la mamoria, pero con mayor responsabilidad, ya que ahora debe gestionarse activamente. 
