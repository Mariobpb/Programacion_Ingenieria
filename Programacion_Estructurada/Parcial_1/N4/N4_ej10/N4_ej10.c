/*
Ejercicio 10: Función elmayor.
Escribir el código de la función que devuelve el factorial de un número que recibe como
argumento. Comprobar que funciona utilizando un programa de prueba como el
siguiente:
int elmayor(int x, int y)
{
//código a escribir
}
void main(void){
int y,x;
printf(“Introduzca un numero:”);
scanf(“%d”,&x);
printf(“Introduzca otro numero:”);
scanf(“%d”,&y);
printf(“El mayor es %d”, elmayor(x,y));
}
*/

#include <stdio.h>

int elmayor(int x, int y)
{
    return x > y ? x : y;
}
void main(void)
{
    int y, x;
    printf("Introduzca un numero:");
    scanf("%d", &x);
    printf("Introduzca otro numero:");
    scanf("%d", &y);
    printf("El mayor es %d", elmayor(x, y));
}