/*
Ejercicio 5: Pasar de días, horas y minutos a segundos

Escribe un programa que pida al usuario los siguientes datos: días, horas y minutos. Y le conteste cuántos segundos en total son esos datos.
*/

#include <stdio.h>

int main() {
    int days;
    int hours;
    int minutes;

    do {
        printf("Ingresa los días a convertir: ");
        scanf("%d", &days);
    } while(days < 0);
    do {
        printf("Ingresa las horas a convertir: ");
        scanf("%d", &hours);
    } while(hours < 0 || hours > 23);
    do {
        printf("Ingresa los minutos a convertir: ");
        scanf("%d", &minutes);
    } while(minutes < 0 || minutes > 59);

    int seconds = ((((days*24)+hours)*60)+minutes)*60;

    printf("Los datos ingresados equivalen a %d segundos", seconds);

    return 0;
}
