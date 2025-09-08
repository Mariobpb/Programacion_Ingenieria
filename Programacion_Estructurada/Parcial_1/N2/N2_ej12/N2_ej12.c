/*
Ejercicio 12: Condición if 4.
Realizar un programa que pida tres números y diga cuál es el mayor, cuál es el segundo
mayor, y cuál es el menor.
*/

#include <stdio.h>

int main()
{
    int nums[3], numsOrd[3], temp;;
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese el numero #%d ", i+1);
        scanf("%d", &nums[i]);
        numsOrd[i] = nums[i];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (numsOrd[i] > numsOrd[j]) {
                temp = numsOrd[i];
                numsOrd[i] = numsOrd[j];
                numsOrd[j] = temp;
            }
        }
    }
    printf("\nNumeros ingresados: %d, %d, %d", nums[0], nums[1], nums[2]);
    printf("\nResultado: %d < %d < %d", numsOrd[0], numsOrd[1], numsOrd[2]);
    
    return 0;
}