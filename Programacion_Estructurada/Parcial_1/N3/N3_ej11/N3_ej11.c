/*
Ejercicio 11: Arrays multidimensionales. Edificio3.
Se quiere controlar el número de habitantes de un eidificio con 6 pisos y 4 puertas (A,
B, C, y D) en cada piso.
Realizar un programa que pida al usuario que introduzca el número de habitantes de
cada puerta del edificio. El programa debe mostrar la media de habitantes de cada piso.
*/

#include <stdio.h>

int main()
{
    int edificio[6][4];
    float mediaHabitantesPiso[6];
    for (int i = 0; i < 6; i++)
    {
        int sumaHabitantes = 0;
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese el numero de habitantes del piso #%d, puerta %c: ", i + 1, 65 + j);
            scanf("%d", &edificio[i][j]);
            sumaHabitantes += edificio[i][j];
        }
        mediaHabitantesPiso[i] = ((float)sumaHabitantes / 4);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("\nLa media de habitantes del piso #%d es de %.2f habitantes", i + 1, mediaHabitantesPiso[i]);
    }

    return 0;
}
