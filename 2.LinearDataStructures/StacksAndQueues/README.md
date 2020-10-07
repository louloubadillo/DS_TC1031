# Stacks and Queues

## Stacks (Pilas)
- Estructura de datos lineal
- Sigue el orden LIFO (Last In First Out), lo que quiere decir que el último elemento en ingresar a la estructura, es el primero en salir. 

### Operaciones
- push(): Agrega un elemento a la pila. Si la pila está llena, se dice que es un overflow. 
- pop(): Elimina un elemento de la pila. Si la pila está vacía, se dice que es un underflow.
- peek(): Devuelve el elemento superior de la fila.
- isEmpty(): Devuelve verdadero si la pila está vacía.

La complejidad de estas operaciones es O(1). 

### Aplicaciones 
- Aunque es una estructura de datos simple de implementar, es muy poderosa. 
- Algunos usos comunes son: 
  - Para invertir una palabra
  - En compiladores. Los compiladores usan la pila para calcular el valor de expresiones al convertirlas en forma prefijo o sufijo. 
  - En los navegadores. 
  - Funciones de rehacer y deshacer. 
  
## Queues (Filas/Colas)
- Estructura de datos lineal
- Sigue el orden FIFO (First In First Out), lo que quiere decir que el último elemento en ingresar a la estructura, es el último en salir. 

### Operaciones
- enqueue(): Añade un elemento al final de la fila. 
- dequeue(): Elimina el elemento del frente de la fila. 
- peek(): Obtiene el elemento al frente de la fila, sin eliminarlo. 
- isEmpty(): Revisa si la fila está vacía. 
  
La complejidad de estas operaciones es O(1). 

### Aplicaciones
- Aunque es una estructura de datos simple de implementar, es muy poderosa. 
- Algunos usos comunes son: 
  - Operaciones en redes de computadoras: 
    - Trabajos envíados a una impresora
    - Solicitudes a un servidor 