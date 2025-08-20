/*
Ejercicio 4: C�lculo de per�metro de circunferencia, �rea del c�rculo y volumen de la esfera

Suponiendo que pi = 3.1416. Escribe un programa que pida al usuario que introduzca el radio, y presente por pantalla
el c�lculo del per�metro de la circunferencia (2pir), el �rea del c�rculo (pir�), y el volumen de la esfera (V = 4pi*r�/3).
*/

#include <stdio.h>

int main() {
    float radius = 0;
    printf("Introduzca el radio para calcular: ");
    scanf("%f", &radius);

    float circumference = (2*3.1416*radius);
    float area = 3.1416*(radius*radius);
    float volume = (4*3.1416*(radius*radius*radius)) / 3;

    printf("De acuerdo al radio ingresado, as� quedar�an los siguientes datos:\nCircunferencia: %.2f unidades\n�rea del c�rculo: %.2f unidades cuadradas\nVolumen de la esfera %.2f unidades c�bicas", circumference, area, volume);

    return 0;
}
