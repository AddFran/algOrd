/*
    Que nos pide el ejercicio?
    Dada una tupla de 5 numeros que van del 1 al 5 (1 <= n <= 5), verificar si se puede formar una expresion
    aritmetica cuyo resultado final sea de 23.
    Reglas a considerar:
        - Deben usarse todos los numeros una sola vez
        - Se puede cambiar el orden de los numeros
        - Solo se puede usar 3 operadores (+ | * | -)
        - La forma de la expresion es fija, estrictamente de izquierda a derecha:
            (((a op a) op a) op a) op a
    Debemos revisar si existe al menos UNA combinacion de numeros y operaciones que den 23
    Si existe alguna forma imprimimos Possible, si no Impossible

    Otra cosilla a considerar es el que:
        - Los 5 numeros puede ordenarse: 5! = 120
        - Hay 4 opciones de operadores que se pueden elegir entre + * -: 3^4 = 81
        - En el peor caso o para confirmar que no existe combinacion posible se evaluan: 120 * 81 = 9720 combinaciones posibles para cada caso,
        con un maximo de 25 linea de entrada, lo que hace que puedan ser 25 * 9720 = 243000 evaluaciones
*/