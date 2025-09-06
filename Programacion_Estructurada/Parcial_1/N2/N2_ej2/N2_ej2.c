/*
Ejercicio 2: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int i=4, x=5;
for(i=0; i<4; i++){
 printf(“>>> %d: %d\n”,i,i*x);
 }
*/

#include <stdio.h>

int main()
{
    int i = 4, x = 5;
    for (i = 0; i < 4; i++)
    {
        printf(">>> %d: %d\n", i, i * x);
    }

    return 0;
}