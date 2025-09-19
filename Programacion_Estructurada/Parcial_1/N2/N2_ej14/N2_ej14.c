/*
Ejercicio 14: Bucles con if 2.
Realizar un programa que pida al usuario dos números y una letra: “i” ó “p”.
El programa presentará los números pares (si se pulsó la “p”) ó impares (si se pulsó la
“i”) que hay desde el primer número al segundo que introdujo el usuario. Si se pulsa
alguna tecla distinta de “p” ó “i”, el programa no imprime ningún número.
*/

#include <stdio.h>

int main()
{
    int numMin, numMax;
    char opcion;
    printf("Ingrese el numero inicial: ");
    scanf("%d", &numMin);
    printf("Ingrese el numero final: ");
    scanf("%d", &numMax);
    printf("Ingrese una opcion (p=par, i=impar): ");
    scanf(" %c", &opcion);

    switch (opcion)
    {
    case 'p':
        printf("Numeros pares: ");
        for (int i = numMin; i <= numMax; i++)
        {
            if ((i % 2 == 0))
                printf("%d ", i);
        }
        break;
    case 'i':
        printf("Numeros impares: ");
        for (int i = numMin; i <= numMax; i++)
        {
            if ((i % 2 == 1) || (i % 2 == -1))
                printf("%d ", i);
        }
        break;
    default:
        break;
    }

    return 0;
}
