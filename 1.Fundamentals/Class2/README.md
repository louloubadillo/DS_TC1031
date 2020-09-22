# Clase 2: Recursividad
La recursión sucede cuando una función se llama a sí misma como parte de su ejecución. <br><br>
Conceptualmente, un problema recursivo es uno que se puede resolver por medio de la solución de instancias más pequeñas del mismo problema. 

## ¿Cómo se usa?
Todas las funciones recursivas requieren de dos partes: 
1. Caso Base 
- Esta parte no se llama a sí misma. 
- Maneja el caso más simple, para el cual ya sabemos la solución. 

2. Caso Recursivo
- Esta parte divide el problema en una versión más simple del problema original. 
- Esta parte hace al menos una llamada a sí misma.

## Memorización 
Es una técnica para hacer algoritmos recursivos más eficientes, la cual consiste en ir almacenando los resultados que ya se han obtenido anteriormente. 