/*
Ejercicio 10: �Qu� imprime?

�Qu� imprime el siguiente fragmento de c�digo? Compru�balo.

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
