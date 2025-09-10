/*
Ejercicio 12: Función divisores.
Escribir el código de la función que imprima por pantalla todos los divisores del número
que recibe como argumento. Comprobar que funciona utilizando un programa de prueba
como el siguiente:
void divisores(int x)
{
//código a escribir
}
void main(void){
int x;
printf(“Introduzca un numero:”);
scanf(“%d”,&x);
divisores(x);
}
*/

#include <stdio.h>

void divisores(int x)
{
    printf("Divisores: ");
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
            printf("%d ", i);
    }
}
void main(void)
{
    int x;
    printf("Introduzca un numero:");
    scanf("%d", &x);
    divisores(x);
}