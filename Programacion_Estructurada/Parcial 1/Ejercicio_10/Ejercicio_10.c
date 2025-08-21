/*
Ejercicio 10: ¿Qué imprime?

¿Qué imprime el siguiente fragmento de código? Compruébalo.

int x = 2, y = 6, z = 4;
y = y%z++;
y = y%z++;
printf("%d", y);
*/

#include <stdio.h>

int main(){
    int x = 2, y = 6, z = 4;
    y = y%z++;
    y = y%z++;
    printf("%d", y);

    return 0;
}
