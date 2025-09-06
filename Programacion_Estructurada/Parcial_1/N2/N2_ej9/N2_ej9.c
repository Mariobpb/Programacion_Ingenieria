/*
Ejercicio 9: Bucles4.
Realizar un programa que imprima por pantalla tántos asteriscos como diga el usuario.
Al ejecutarse debe preguntar “Cuantos asteriscos desea imprimir?”, leer el número que
introduce el usuario e imprimir los asteriscos.
*/

#include <stdio.h>

int main()
{
    int num = 0;
    printf("Cuantos asteriscos desea imprimir? ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("*");
    }
    
    return 0;
}