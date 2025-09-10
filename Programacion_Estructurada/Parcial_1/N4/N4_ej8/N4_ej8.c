/*
Ejercicio 8: Función cuadrado.
Escribir el código de la función que devuelve el cuadrado de un número que recibe
como argumento. Comprobar que funciona utilizando un programa de prueba como el
siguiente:
int cuadrado(int x)
{
//código a escribir
}
void main(void){
int y=4;
printf(“Introduzca un numero:”);
scanf(“%d”,&x);
printf(“Su factorial es %d”, cuadrado(x));
}
*/

#include <stdio.h>

int cuadrado(int x)
{
    return x*x;
}
void main(void)
{
    int x;
    printf("Introduzca un numero:");
    scanf("%d", &x);
    printf("Su cuadrado es %d", cuadrado(x));
}