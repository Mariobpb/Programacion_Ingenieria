/*
Ejercicio 6: Pasar de segundos a días, horas y minutos

Escribe un programa que pida al usuario que introduzca los segundos, y le conteste diciéndole el número de días, horas, minutos y segundos que son.
*/

#include <stdio.h>

int main(){
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    int days = 0;

    printf("Ingrese los segundos a converitir: ");
    scanf("%d", &seconds);

    if(seconds >= 60) {
        minutes += seconds/60;
        seconds -= minutes*60;
    }
    if(minutes >= 60) {
        hours += minutes/60;
        minutes -= hours*60;
    }
    if(hours >= 24){
        days += hours/24;
        hours -= days*24;
    }

    printf("De acuerdo a los segundos ingresados, se convierte en:\nDías: %d\nHoras: %d\nMinutos: %d\nSegundos: %d", days, hours, minutes, seconds);


    return 0;
}
