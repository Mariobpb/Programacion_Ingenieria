/*
Crea una función mayorDeTres(int a, int b, int c) que devuelva el número más grande.
*/

#include <stdio.h>

int mayorDeTres(int, int, int);

int main()
{
    printf("El mayor es: %d\n", mayorDeTres(9, 2, 11));
    return 0;
}

int mayorDeTres(int a, int b, int c){
    int numMayor = a;
    if (b > numMayor)
        numMayor = b;
    if (c > numMayor)
        numMayor = c;
    return numMayor;
}