/*
Ejercicio 9: Media de cuatro números

Escribir un programa que pida por teclado cuatro números y calcule y presente la media de los cuatro.
*/

#include <stdio.h>

int main() {
    int numbers[4];
    int i = 0;
    float average = 0;

    do{
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &numbers[i]);
        average += numbers[i];
        i++;
    }while(i <= 3);

    average /= 4;
    printf("La media de los números es: %.3f", average);

    return 0;
}
