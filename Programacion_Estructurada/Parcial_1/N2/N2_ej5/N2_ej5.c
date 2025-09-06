/*
Ejercicio 5: ¿Qué imprime?.
¿Qué imprime el siguiente fragmento de código? Compruébalo.
int i=4, x=5;
for(i=0; i<10; i++){
 if(i<x) printf(“%d ”,i);
 else printf(“%d ”,i-x);
 }
*/

#include <stdio.h>

int main()
{
    int i = 4, x = 5;
    for (i = 0; i < 10; i++)
    {
        if (i < x)
            printf("%d ", i);
        else
            printf("%d ", i - x);
    }
    
    return 0;
}