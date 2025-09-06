/*
Ejercicio 11: Condición if 3.
Realizar un programa que pregunte al usuario el momento del día con una letra (mmañana, t-tarde, n-noche), el sexo con otra letra (m-masculino, f-femenino). El
programa dirá: buenos días, tardes, o noches (según el momento) señor o señora según
el sexo.
*/

#include <stdio.h>

int main()
{
    char momento, sexo;
    printf("Ingrese el momento del dia (m=mañana, t=tarde, n=noche): ");
    scanf(" %c", &momento);
    printf("Ingrese el sexo (m=masculino, f=femenino): ");
    scanf(" %c", &sexo);
    switch (momento)
    {
    case 'm':
        printf("Buenos dias ");
        break;
    case 't':
        printf("Buenas tardes ");
        break;
    case 'n':
        printf("Buenas noches ");
        break;
    default:
        break;
    }
    if (sexo == 'm')
        printf("señor");
    else
        printf("señora");

    return 0;
}