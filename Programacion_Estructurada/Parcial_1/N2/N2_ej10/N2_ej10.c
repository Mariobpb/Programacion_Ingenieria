/*
Ejercicio 10: Condición if 2.
Realizar un programa que pida tres números y diga cuáles son pares y cuáles impares.
*/

#include <stdio.h>

int main()
{
    int nums[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese el numero #%d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        if ((nums[i] % 2 == 1) || (nums[i] % 2 == -1))
            printf("%d impar\n", nums[i]);
        else
            printf("%d par\n", nums[i]);
    }

    return 0;
}