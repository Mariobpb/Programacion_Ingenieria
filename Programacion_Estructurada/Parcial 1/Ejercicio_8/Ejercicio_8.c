/*
Ejercicio 8: Cálculo de la resistencia equivalente

Escribir un programa que pida por teclado dos resistencias y calcule y presente la resistencia equivalente en paralelo:
Req = (R1 * R2) / (R1 + R2)
*/

#include <stdio.h>

int main(){
    int R1 = 0;
    int R2 = 0;
    float Rf = 0;

    do{
        printf("Ingrese en ohms la resistencia R1: ");
        scanf("%d", &R1);
    }while(!(R1 > 0));
    do{
        printf("Ingrese en ohms la resistencia R1: ");
        scanf("%d", &R2);
    }while(!(R2 > 0));

    Rf = ((float)R1 * R2) / (R1 + R2);
    printf("Rf = %.2f", Rf);

    return 0;
}
