#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char materias[8][25], tempM[25];
    int calificaciones[8];
    for (int materia = 0; materia < 8; materia++)
    {
        printf("Ingrese el nombre de la materia #%d:\n", materia+1);
        bool stringVerified = false;
        do{
            fgets(tempM, 25, stdin);
            int n = 0;
            while(tempM[n] != '\0' && tempM[n] != '\n'){
                if((tempM[n] >= 'a' && tempM[n] <= 'z') || (tempM[n] >= 'A' && tempM[n] <= 'Z'))
                {
                    n++;
                    if(tempM[n] == '\0' || tempM[n] == '\n')
                    {
                        tempM[n] = '\0';
                        stringVerified = true;
                        break;
                    }
                }
                else {
                    printf("Caracteres inválidos\n");
                    break;
                }
            }
            if (stringVerified) strcpy(materias[materia], tempM);
        }while(!stringVerified);
        printf("Ingrese la calificación de la materia %s:\n", materias[materia]);
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
    
    return 0;
}