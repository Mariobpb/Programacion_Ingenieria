/*
Ejercicio 11: Función escribe_asteriscos.
Escribir el código de la función que imprima por pantalla tantos asteriscos como indique
el número que recibe como argumento. Comprobar que funciona utilizando un
programa de prueba como el siguiente:
void escribe_asteriscos(int x)
{
//código a escribir
}
void main(void){
int y,x;
printf(“Introduzca un numero:”);
scanf(“%d”,&x);
escribe_asteriscos (x);
}
*/

#include <stdio.h>

void escribe_asteriscos(int x)
{
    for (int i = 0; i < x; i++)
        printf("*");
}
void main(void)
{
    int y, x;
    printf("Introduzca un numero:");
    scanf("%d", &x);
    escribe_asteriscos(x);
}