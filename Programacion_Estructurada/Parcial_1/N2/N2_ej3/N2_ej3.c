/*
Ejercicio 3: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int i=4, x=5;
for(i=x; i<10; i++){
 printf(“%d, ”,i);
 }
*/

#include <stdio.h>

int main()
{
    int i = 4, x = 5;
    for (i = x; i < 10; i++)
    {
        printf("%d, ", i);
    }

    return 0;
}