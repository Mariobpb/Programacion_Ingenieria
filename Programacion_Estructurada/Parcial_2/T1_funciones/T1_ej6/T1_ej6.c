/*
La función esPar(int n) debe devolver 1 si el número es par y 0 si es impar. Desde main() imprime el
mensaje correspondiente.
*/

#include <stdio.h>

int esPar(int);

int main()
{
    int n = 3;
    if (esPar(n))
        printf("%d es par.\n", n);
    else
        printf("%d es impar.\n", n);
    
    return 0;
}

int esPar(int n)
{
    return n % 2 == 0;
}