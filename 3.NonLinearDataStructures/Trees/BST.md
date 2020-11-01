# Binary Search Trees (BST) 
Es un tipo de árbol que permite almacenar información ordenada. 
Tiene que seguir las siguientes reglas: 
1. Cada nodo del árbol puede tener 0, 1 o 2 hijos
2. Los descendientes izquierdos deben tener valores menores al padre
3. Los descendientes derechos deben tener valores mayores al padre

## Buscar Nodos

```cpp
struct node* search(struct node* root, int key) { 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 
```
## Agregar Nodo
Reglas: 
1. El valor a insertar no existe en el árbol (no pueden haber duplicados)
2. El nuevo nodo será un nodo hoja del árbol

Procedimiento: 
1. Buscar el nodo padre del nodo a agregar
2. Agregar el nodo

Notas: 
- El orden de inserción de los datos, determina la forma del BST. 
- Si los datos se insertan de forma ordenada, queda como una lista enlazada. Esto es conocido como un árbol desbalanceado. 
- Por lo tanto, la forma del árbol determina la eficiencia del proceso de búsqueda.
- Entre menos altura tenga el árbol, es más eficiente, ya que está mejor balanceado. 