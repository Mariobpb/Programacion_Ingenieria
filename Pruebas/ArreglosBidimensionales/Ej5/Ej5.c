/*
Elabore una aplicación que convierta una matriz  de 4 x 3 (Almacenada por el usuario),
 en un arreglo unidimensional de 12 posiciones. La conversión debe hacerse por
 columnas, es decir, mover la primera columna al vector, a continuación la segunda
 columna y así sucesivamente. Imprima ambos arreglos.
*/

#include <stdio.h>

int main()
{
    int matriz[4][3], arreglo[12], iArreglo = 0;
    ;
    printf("Ingrese los elementos de la matriz 4x3:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz[i][j]);
    }
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            arreglo[iArreglo] = matriz[i][j];
            iArreglo++;
        }
    }
    printf("\nMatriz 4x3:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\nArreglo unidimensional de 12 posiciones:\n");
    for (int i = 0; i < 12; i++)
        printf(" %d ", arreglo[i]);
}