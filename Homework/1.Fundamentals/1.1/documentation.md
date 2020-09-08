# Documentación 

## Métodos
1. sumaIterativa	
- Descripción: Calcule la sumatoria de 1 hasta n con un metodo iterativo.
- Entrada: Un entero positivo (n)
- Salida: La sumatoria de 1 hasta n
- Precondición: n es un entero positivo
- Postcondición: Nada

2. sumaRecursiva	
- Descripción: Calcule la sumatoria de 1 hasta n con un metodo recursivo.
- Entrada: Un entero positivo (n)
- Salida: La sumatoria de 1 hasta n
- Precondición: n es un entero positivo
- Postcondición: Nada

3. sumaDirecta	
- Descripción: Calcule la sumatoria de 1 hasta n con un metodo matemático directo.
- Entrada: Un entero positivo (n)
- Salida: La sumatoria de 1 hasta n
- Precondición: n es un entero positivo
- Postcondición: Nada
  
## Complejidad del Algoritmo
1. sumaIterativa: O(n)
2. sumaRecursiva: O(n)
3. sumaDirecta: O(1)

## Plan de Pruebas
1. Número entero positivo
   - Entrada: n = 100
   - Salida esperada: 5050
   - Resultado: Funciona para los 3 métodos
2. Entrada 1
   - Entrada: n = 1
   - Salida esperada: 1
   - Resultado: Funciona para los 3 métodos
3. Entrada 0
   - Entrada: n = 0
   - Salida esperada: 0
   - Resultado: Funciona para los 3 métodos
4. Número entero negativo 
   - Entrada: n = -2
   - Salida esperada: Mensaje de error y regresar -1 
   - Resultado: Funciona para los 3 métodos
