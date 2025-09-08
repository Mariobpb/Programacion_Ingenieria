/*
Ejercicio 17: Bucles con if 5. 
Realizar un programa que pida que se tres números consecutivos (3, 4 y 5; 9, 10 y 11, 
etc.). Cuando se introducen tres números consecutivos dice “gracias” y termina. Mientras no se 
introduzcan tres números consecutivos el programa sigue pidiendo números indefinidamente.
*/

#include <stdio.h>

int main()
{
    int num1, num2, num3;
    do{
    printf("Ingrese primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese tercer numero: ");
    scanf("%d", &num3);
    } while(!((num2 == num1+1) && (num3 == num1+2)));
    printf("Gracias");
    
    return 0;
}
