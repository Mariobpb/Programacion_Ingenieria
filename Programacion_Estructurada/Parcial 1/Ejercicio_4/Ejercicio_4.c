/*
Ejercicio 4: Cálculo de perímetro de circunferencia, área del círculo y volumen de la esfera

Suponiendo que pi = 3.1416. Escribe un programa que pida al usuario que introduzca el radio, y presente por pantalla
el cálculo del perímetro de la circunferencia (2pir), el área del círculo (pir²), y el volumen de la esfera (V = 4pi*r³/3).
*/

#include <stdio.h>

int main() {
    float radius = 0;
    printf("Introduzca el radio para calcular: ");
    scanf("%f", &radius);

    float circumference = (2*3.1416*radius);
    float area = 3.1416*(radius*radius);
    float volume = (4*3.1416*(radius*radius*radius)) / 3;

    printf("De acuerdo al radio ingresado, así quedarían los siguientes datos:\nCircunferencia: %.2f unidades\nÁrea del círculo: %.2f unidades cuadradas\nVolumen de la esfera %.2f unidades cúbicas", circumference, area, volume);

    return 0;
}
