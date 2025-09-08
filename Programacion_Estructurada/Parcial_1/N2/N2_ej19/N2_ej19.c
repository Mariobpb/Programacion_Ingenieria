/*
Ejercicio 19: Bucles con if7. Ecuación de 2º grado. 
Realizar un programa que pida dos números y presente por pantalla la ecuación de 
segundo grado que tiene por soluciones estos dos números. Ejemplo: 5 y -3, la ecuación sería 
(x-5) (x+3) = x2-2x-15, los coeficientes son 1, -2 y -15. El programa permitirá repetir esta 
operación tantas veces como el usuario quiera, introduciendo números diferentes, hasta que 
decida terminar el programa  (por ejemplo pulsando ‘S’). 
*/

#include <stdio.h>

int main()
{
    char opcion = 'C';
    int num1, num2, coef1, coef2, coef3;
    do
    {
        printf("Ingrese el primer numero: ", num1);
        scanf("%d", &num1);
        printf("Ingrese el segundo numero: ", num2);
        scanf("%d", &num2);
        coef1 = 1;
        coef2 = num1 + num2;
        coef3 = num1 * num2;
        printf("Ecuación: (x");
        if(num1 >= 0)
            printf("+");
        printf("%d)(x", num1);
        if(num2 >= 0)
            printf("+");
        printf("%d) = x2", num2);
        if(coef2 >= 0)
            printf("+");
        printf("%dx", coef2);
        if(coef3 >= 0)
            printf("+");
        printf("%d\nLos coeficientes son a=%d, b=%d, c=%d", coef3, coef1, coef2, coef3);
        printf("\nPulse 'S' para salir: ");
        scanf(" %c", &opcion);
    } while (opcion != 'S');
    
    return 0;
}
