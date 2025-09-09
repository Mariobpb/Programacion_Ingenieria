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
    int edificio[6][4], sumaHabitantes = 0, mediaHabitantes;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese el numero de habitantes del piso #%d, puerta %c: ", i + 1, 65 + j);
            scanf("%d", &edificio[i][j]);
            if (edificio[i][j] > habitantesMax){
                habitantesMax = edificio[i][j];
                pisoMax = i;
                puertaMax = j;
            }
        }
    }
    printf("\nLa vivienda con mas habitantes se encuentra en el piso #%d, puerta %c, con %d habitantes", pisoMax + 1, 65 + puertaMax, habitantesMax);
    
    return 0;
}
