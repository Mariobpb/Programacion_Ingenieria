/*
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int calificaciones[8];
    for (int materia = 0; materia < 8; materia++)
    {
        printf("Ingrese la calificación de la materia #%d:\n", materia+1);
        int intentos = 3;
        do{
            scanf("%d", &calificaciones[materia]);
            if(calificaciones[materia] < 0 || calificaciones[materia] > 100) {
                printf("Calificación inválida\n");
                intentos--;
                if (intentos == 0)
                {
                    printf("Intentos agotados, definiendo calificación como 0...\n");
                    calificaciones[materia] = 0;
                    break;
                }
            } else break;
        } while(intentos > 0);
    }
    printf("\nCalificaciones ingresadas:\n");
    for (int m = 0; m < 8; m++)
    {
        printf("\nMateria #%d: %d", m+1, calificaciones[m]);
    }
    
    return 0;
}