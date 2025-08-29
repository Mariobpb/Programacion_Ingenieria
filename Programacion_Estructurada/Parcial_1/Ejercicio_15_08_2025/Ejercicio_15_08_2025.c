#include <stdio.h>
#include <stdbool.h>


int main() {
    char cadena[25];
    bool cadVerificada = false;
    do {
        printf("Ingrese una cadena: ");
        fgets(cadena, 26, stdin);
        int i = 0;
        while (cadena[i] != '\n')
        {
            if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))){
                printf("Cadena inválida, ingrese otra:\n");
                break;
            }
            i++;
            if((cadena[i] == '\n') || (i == 25)) {
                cadVerificada = true;
                cadena[i] = '\0';
                break;
            }
        }
    } while (!cadVerificada);

    return 0;
}