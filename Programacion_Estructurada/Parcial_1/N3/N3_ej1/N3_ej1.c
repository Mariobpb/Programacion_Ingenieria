/*
 Ejercicio 1: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int array[10]={1,3,5,7,9,2,3,4,6,8,10},i;
for(i=0; i<10; i++){
printf(“>>> %d\n”, array[i]);
}
*/

#include <stdio.h>

int main()
{
    int array[10] = {1, 3, 5, 7, 9, 2, 3, 4, 6, 8, 10}, i;
    for (i = 0; i < 10; i++)
    {
        printf(">>> %d\n", array[i]);
    }

    return 0;
}
