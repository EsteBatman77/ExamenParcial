Código realizado por:
Esteban Díaz López
Ana Carolina García Morales

Código para Mbed - Teclado Matricial y Funciones Matemáticas
Este repositorio contiene un programa para una plataforma Mbed que utiliza un teclado matricial para realizar tres tipos de operaciones matemáticas diferentes: calcular la pendiente e intersección de una recta, calcular el promedio y la desviación estándar de un conjunto de temperaturas, y controlar un LED RGB utilizando un código hexadecimal.

Configuración del Hardware
Este programa está diseñado para funcionar con un teclado matricial y un microcontrolador compatible con la plataforma Mbed. La configuración de hardware necesaria incluye:

Un teclado matricial con 4 filas y 3 columnas.
Un microcontrolador Mbed compatible con pines GPIO para conectar el teclado matricial.
Un LED RGB conectado a pines GPIO para el control de color.
Asegúrate de conectar correctamente el teclado matricial y el LED RGB a tu microcontrolador antes de ejecutar el programa.

Funcionalidades
1. Calcular Pendiente e Intersección
Esta funcionalidad permite al usuario ingresar las coordenadas de dos puntos (x1, y1) y (x2, y2) y calcular la pendiente y la intersección de la recta que pasa por esos puntos. La lógica detrás de esta función es la siguiente:

El usuario ingresa las coordenadas (x1, y1) y (x2, y2) utilizando el teclado matricial.
Se verifica si x1 es igual a x2 para determinar si la pendiente es indeterminada (división por cero).
Si x1 no es igual a x2, se calcula la pendiente (m) utilizando la fórmula (y2 - y1) / (x2 - x1) y la intersección con el eje y (b) utilizando la fórmula y1 - (m * x1).
Los resultados se muestran en la pantalla./n
2. Calcular Promedio y Desviación Estándar
La segunda funcionalidad permite al usuario ingresar una serie de temperaturas y luego calcular el promedio y la desviación estándar de esas temperaturas. La lógica detrás de esta función es la siguiente:

El usuario ingresa la cantidad de temperaturas que desea ingresar utilizando el teclado matricial.
Luego, el usuario ingresa las temperaturas una por una.
Se calcula el promedio sumando todas las temperaturas y dividiendo por la cantidad.
Se calcula la desviación estándar utilizando la fórmula matemática correspondiente./n

3. Controlar un LED RGB
La tercera funcionalidad permite al usuario ingresar un código hexadecimal de 6 caracteres y utilizarlo para controlar un LED RGB. La lógica detrás de esta función es la siguiente:

El usuario ingresa el código hexadecimal utilizando el teclado matricial.
Se verifica si el código tiene 6 caracteres.
El código se divide en tres partes: RR (rojo), GG (verde) y BB (azul).
Cada parte se convierte de hexadecimal a decimal y se normaliza para obtener un valor entre 0 y 1.
Los valores normalizados se utilizan para controlar la intensidad de los colores en el LED RGB./n
Uso del Teclado Matricial
Utiliza las teclas numéricas (1, 2, 3) para seleccionar una de las tres funcionalidades.
Ingresa datos numéricos o códigos hexadecimales utilizando el teclado matricial.
Utiliza '#' para confirmar la entrada y '*' para limpiar la entrada actual./n
Cómo Ejecutar el Programa
Asegúrate de tener la plataforma Mbed configurada y conectada al hardware necesario.
Copia y pega el código proporcionado en un nuevo proyecto Mbed.
Compila y carga el programa en tu microcontrolador.
Ejecuta el programa en el microcontrolador.
