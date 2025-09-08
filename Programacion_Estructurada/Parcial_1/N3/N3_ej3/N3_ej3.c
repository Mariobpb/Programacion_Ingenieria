/*
Ejercicio 3: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int array[10],i;
for(i=0; i<10; i++){
array[i]=i*i;
}
for(i=0; i<10; i++){
printf(“%d”,array[i]);
}
*/

#include <stdio.h>

int main()
{
    int array[10], i;
    for (i = 0; i < 10; i++)
    {
        array[i] = i * i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d", array[i]);
    }

    return 0;
}
