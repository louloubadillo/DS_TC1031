# Linked Lists

## ¿Qué son? 
Una lista enlazada está compuesta por una secuencia de nodos. 

## Terminología 
- Head (cabeza): Apunta al primer nodo de la lista
- Tail (cola): Apunta al último nodo de la lista
- Sucesor: El nodo siguiente en la secuencia 
- Predecesor: El nodo anterior en la secuencia 
- Tamaño/longitud: cantidad de elementos en ella
  - La lista puede estar vacía (head apunta a null)

## Double Linked List
La lista tiene un apuntador al nodo sucesor y al nodo predecesor. 
``` cpp
class DoubleNode{
    private: 
        int value; 
        DoubleNode *next, *prev; 
    public: 
        DoubleNode(int v, DoubleNode *_next, DoubleNode *_prev);
}
``` 

## Circular Linked List
El último nodo tiene un apuntador al head node. 

## Operaciones

### Push (Añadir al inicio)
- El método crea un nodo y lo añade al inicio de la lista
  
### Traverse (Recorrer) 
- Comenzar por la cabeza y acceder a cada nodo (next) hasta que se llegue a NULL. 
- No cambiar la referencia a la cabeza. 
  
### Append (Añadir al final)
- Crear un nodo y añadirlo al final de la lista. 
- Requiere recorrer la lista pero debe detenerse en el último nodo. 

### Insert
Para insertar un nodo debo: 
- Crear un nodo
- Crear conexiones
- Eliminar conexión restante

### Erase
Para eliminar un nodo debo: 
- Fijar un apuntador del predecesor al nodo siguiente
- Eliminar el nodo y su conexión
- Liberar toda memoria asociada al mismo ( si se usó memoria dinámica)

### Get Element 
Para obtener el elemento n debo: 
- Recorrer la lista, incrementando un contador hasta llegar al n-ésimo elemento 
- Usar la conexión 
  
## Ventajas y Desventajas
Ventajas
- Insertar un elemento es O(1)

Desventajas
- Acceder a un elemento es O(n)