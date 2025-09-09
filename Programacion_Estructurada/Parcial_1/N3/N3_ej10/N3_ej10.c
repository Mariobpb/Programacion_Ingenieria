/*
Ejercicio 10: Arrays multidimensionales. Edificio3.
Se quiere controlar el número de habitantes de un eidificio con 6 pisos y 4 puertas (A,
B, C, y D) en cada piso.
Realizar un programa que pida al usuario que introduzca el número de habitantes de
cada puerta del edificio. El programa debe decir la puerta que más habitantes tiene de
todo el edificio.
*/

#include <stdio.h>

int main()
{
    int edificio[6][4], habitantesGrupoPuertas[4], puertaMax, habitantesMax = 0;
    for (int i = 0; i < 4; i++)
        habitantesGrupoPuertas[i] = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese el numero de habitantes del piso #%d, puerta %c: ", i + 1, 65 + j);
            scanf("%d", &edificio[i][j]);
            habitantesGrupoPuertas[j] += edificio[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (habitantesGrupoPuertas[i] > habitantesMax)
        {
            habitantesMax = habitantesGrupoPuertas[i];
            puertaMax = i;
        }
    }
    printf("\nEl grupo de puertas con mas habitantes es el %c, con %d habitantes", 65 + puertaMax, habitantesMax);

    return 0;
}
