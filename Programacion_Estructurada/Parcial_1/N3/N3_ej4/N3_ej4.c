/*
Ejercicio 4: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int array[10],i=0;
while(i<10){
array[i]=i*i;
i++;
}
do{
printf(“%d”,array[--i]);
} while(i>=0);
*/

#include <stdio.h>

int main()
{
    int array[10], i = 0;
    while (i < 10)
    {
        array[i] = i * i;
        i++;
    }
    do
    {
        printf("%d", array[--i]);
    } while (i >= 0);

    return 0;
}
