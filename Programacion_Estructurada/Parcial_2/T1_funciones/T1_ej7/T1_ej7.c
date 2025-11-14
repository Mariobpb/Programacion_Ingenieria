/*
Prototipo: float promedio(int arr[], int n); Debe devolver el promedio de los n elementos del arreglo.
*/

#include <stdio.h>

float promedio(int[], int);

int main()
{
    int arreglo[5] = {80, 72, 53, 71, 98};
    printf("Promedio: %.2f\n", promedio(arreglo, 5));
    return 0;
}

float promedio(int arreglo[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arreglo[i];
    return sum / (float)n;
}