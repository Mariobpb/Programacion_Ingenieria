#include <stdio.h>

void captCadena(char* c);
void copiarAlfCadena(char* ct, char* cr);
void impCadenas(char* c, char* c2);

int main() {
    char cadTemp[40], cadR[40];
    captCadena(cadTemp);
    copiarAlfCadena(cadTemp, cadR);
    impCadenas(cadTemp, cadR);
    return 0;
}

void captCadena(char* c){
    printf("Ingrese la cadena deseada: ");
    fgets(c, 40, stdin);
}
void copiarAlfCadena(char* ct, char* cr){
    while (*ct != '\0' && *ct != '\n')
    {
        if ((*ct >= 'a' && *ct <= 'z') || (*ct >= 'A' && *ct <= 'Z'))
        {
            *cr = *ct;
            cr++;
        }
        ct++;
    }
    *cr = '\0';
}
void impCadenas(char* c1, char* c2){
    printf("Cadena ingresada: %s", c1);
    printf("Cadena resultante: %s", c2);
}