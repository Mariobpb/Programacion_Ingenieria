/*

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char materias[8][25], tempM[25];
    for(int m = 0; m < 8; m++){
        printf("Ingrese el nombre de la materia #%d:\n", m+1);
        bool stringVerified = false;
        do{
            fgets(tempM, 25, stdin);
            int n = 0;
            while(tempM[n] != '\0' || tempM[n] != '\n'){
                if((tempM[n] >= 'a' && tempM[n] <= 'z') || (tempM[n] >= 'A' && tempM[n] <= 'Z'))
                {
                    n++;
                    if(tempM[n] == '\0' || tempM[n] == '\n')
                    {
                        stringVerified = true;
                        break;
                    }
                }
                else {
                    printf("Caracteres inválidos\n");
                    break;
                }
            }
            if (stringVerified) strcpy(materias[m], tempM);
        }while(!stringVerified);
    }
    return 0;
}
