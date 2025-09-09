/*
Ejercicio 9: Arrays multidimensionales. Edificio2.
Se quiere controlar el número de habitantes de un eidificio con 6 pisos y 4 puertas (A,
B, C, y D) en cada piso.
Realizar un programa que pida al usuario que introduzca el número de habitantes de
cada puerta del edificio. El programa debe decir el piso que más habitantes tiene de todo
el edificio.
*/

#include <stdio.h>

int main()
{
    int edificio[6][4], habitantesMax = 0, pisoMax;
    for (int i = 0; i < 6; i++)
    {
        int sumaHabitantes = 0;
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese el numero de habitantes del piso #%d, puerta %c: ", i + 1, 65 + j);
            scanf("%d", &edificio[i][j]);
            sumaHabitantes += edificio[i][j];
        }
        if (sumaHabitantes > habitantesMax){
            habitantesMax = sumaHabitantes;
            pisoMax = i;
        }
    }
    printf("\nEl piso con mas habitantes es en el piso #%d, con %d habitantes", pisoMax + 1, habitantesMax);

    return 0;
}
