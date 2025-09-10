/*
Ejercicio 9: Función factorial.
Escribir el código de la función que devuelve el factorial de un número que recibe como
argumento. Comprobar que funciona utilizando un programa de prueba como el
siguiente:
int factorial(int x)
{
//código a escribir
}
void main(void){
int y=4;
printf(“Introduzca un numero:”);
scanf(“%d”,&x);
printf(“Su factorial es %d”, factorial(x));
}
*/

#include <stdio.h>

int factorial(int x)
{
    int res = 1;
    for (int i = 1; i <= x; i++)
        res *= i;

    return res;
}
void main(void)
{
    int x;
    printf("Introduzca un numero:");
    scanf("%d", &x);
    printf("Su factorial es %d", factorial(x));
}