/*
Ejercicio 4: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int i=4, x=5;
if(x<(2*i))
 printf(“verdadero”);
else
 printf(“falso”);
*/

#include <stdio.h>

int main()
{
    int i = 4, x = 5;
    if (x < (2 * i))
        printf("verdadero");
    else
        printf("falso");

    return 0;
}