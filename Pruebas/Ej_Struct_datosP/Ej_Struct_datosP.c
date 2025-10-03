#include <stdio.h>

typedef struct {
    char name[50];
    char email[50];
    char registro[12];
} datos_P;

datos_P ingresarDatos(void) {
    datos_P T;
    printf("nombre: ");
    fgets(T.name, 50, stdin)

    return T;
}
int main(){
    
}