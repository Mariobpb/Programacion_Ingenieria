/*
Ejercicio 25: Simplificar fracciones.
Realizar un programa que pida el numerador y denominador de una fracción y devuelva la
fracción simplificada.
*/

#include <stdio.h>

int main()
{
    int num, den, numRes, denRes, mcm;
    printf("\nPrimera fraccion:\n\nNumerador: ");
    scanf("%d", &num);
    printf("Denominador: ");
    scanf("%d", &den);
    printf("Fraccion simplificada: ");
    for (int i = 1; i <= den; i++)
        if ((den % i == 0) && (num % i == 0))
            mcm = i;
    numRes = (num / mcm);
    denRes = (den / mcm);
    printf("%d/%d = %d", num, den, numRes);
    if (denRes != 1)
        printf("/%d", denRes);

    return 0;
}
