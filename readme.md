# Proyecto: Steal a Brainrot!
## César Daniel Aguilar Kuri - A01712823
Steal a Brainrot! es un juego de Roblox que consiste en coleccionar y robar diferentes personajes catalogados como "Brainrot", este juego tiene un sistema de rarezas (Common, Rare, Epic, Legendary, BrainrotGod y Secret) y costos en cuestión a los personajes que existen, por lo que es más valioso un Brainrot Secret a un Brainrot Common. Usando los diferentes temas que hemos aprendido durante el semestre, este proyecto se designa a facilitar la busqueda y catalogo de los Brainrots que el usuario tiene en el juego, mejorando el ordenamiento en su base dependiendo si quiere ordenarlos por nombre, costo o rareza.

## Descripción del avance 1
En este avance se entrega un primer prototipo de consola que:
+ Pide al usuario diferentes brainrots que añadir a vectores como Nombre, Rareza y Costo.
+ Permite consultar arreglos con datos ya ingresados por el usuario.
+ Implementa un algoritmo de ordenamiento: Bubble Sort.

Permite elegir criterios de orden:
+ (Bubble Sort) Costo (Menor a Mayor).
+ (Insertion Sort) Rareza (Menor a Mayor) PENDIENTE.
+ (Merge Sort) Nombre (Alfabético) PENDIENTE.

Este avance solo tiene por el momento un algoritmo de busqueda (bubble sort), el cual se efectua por costo del personaje.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Para el avance de proyecto 1, se necesita ingresar nombres de personajes brainrot (ejemplo: Tralalero Tralala, Orcalero Orcala, Lirili Larila, Cappuchino Assasino, etc.), su rareza (ejemplo: common, rare, epic, legendary, brainrotgod, secret) y costo (varía, puedes poner cualquier numero que NO sea negativo). Si no se hace esto al inicio del programa, no te dejará hacer bubble sort ni consultar los arreglos (los datos permitidos se los hará saber el programa). Al ser personajes creados con IA, en un futuro pueden existir muchisimos más personajes que en el proyecto no se agregan (debido a la gran cantidad, por lo que dejamos al usuario agregar los que el tiene). SE RECOMIENDA AGREGAR MÁS DE 2 PERSONAJES, SI SON 2 PERSONAJES NO SE PODRÁ OBSERVAR EL DESEMPEÑO TOTAL DE LOS ALGORITMOS DE BUSQUEDA.

## Descripción de las salidas del avance de proyecto
Al terminar de ejecutar el avance, se puede obtener:
+ Los arreglos sin ordenar.
+ Los arreglos ordenados por su costo (menor a mayor) con Bubble Sort.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Algoritmo implementado en el Avance 1: Bubble Sort en tres arreglos paralelos (nombre, rareza, costo), con criterio de orden definido (por costo -> nombre, y/o rareza -> costo -> nombre).

Complejidad temporal (clasificación pedida):
+ Mejor caso: O(n) — cuando la lista ya está ordenada (activamos corte temprano al no haber swaps).
+ Promedio: O(n²) — recorridos anidados comparando pares adyacentes.
+ Peor caso: O(n²) — lista en orden inverso o muy desordenada.
+ O(log n), O(log log n): no aplican en Bubble Sort.
+ Espacio adicional: O(1) — solo variables temporales y swap de “fila”.

Dónde se observa en el código:
+ Función bubbleSortPorCosto() en BubbleSort.h:
+ bucle externo que reduce el rango (n pasadas máx.)
+ bucle interno que compara adyacentes (≈ n comparaciones por pasada)
+ if (!huboSwap) break; -> justifica el O(n) del mejor caso
+ swapFila() mantiene la coherencia de los 3 arreglos con O(1) por intercambio (para que no se vuelva un caos).

Para este avance documenté y justificé correctamente O(1), O(n), O(n²) y se aclara la inexistencia de O(log n) y O(log log n) o notaciones de Big O más complejas para este algoritmo, además, se respalda con la estructura exacta de bucles del código. Adicionalmente, cada línea de métodos importantes está comentada con su respectiva notación para analizarla profundamente y poder obtener una idea de complejidad final.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Decisión tomada en el Avance 1: usar Bubble Sort para el primer corte funcional porque:

Es simple de implementar y revisar en arreglos paralelos (tres columnas, las cuales son Nombres, Rarezas y Costos), fundamental para verificar reglas de negocio (rareza/costo/nombre) sin introducir complejidad extra.
Tiene O(1) de memoria adicional y un mejor caso O(n) con corte temprano, útil cuando el usuario va agregando datos y la lista queda casi ordenada, adicionalmente, permite validar la jerarquía de rarezas (Common, Rare, Epic...) y desempates, asegurando que el resultado respeta el valor del juego.

Uso correcto demostrado:
+ Coherencia de registros: cada swap mueve nombre/rareza/costo juntos (swapFila), evitando desalineaciones.
+ Criterio determinista: desempate por costo y luego nombre; o rareza -> costo -> nombre si se elige esa variante.
+ Validación de entrada: rarezas restringidas al catálogo, costos ≥ 0. Esto evita casos que rompan el orden.

Dónde se ve en el proyecto:
Menú opción 3 (Bubble) + BubbleSort.h (reglas y swaps). Las capturas (opción 1) permanecen en memoria, permitiendo repetir el sort y observar el comportamiento O(n) vs O(n²) según el estado de los datos.
