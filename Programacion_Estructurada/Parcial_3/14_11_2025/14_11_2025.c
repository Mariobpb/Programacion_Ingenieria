#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *lastname;
    char *email;
    int age;

} datosP;

void ingresarPersona(datosP*);
void mostrarPersona(datosP p);

int main(){
    datosP persona[5], personasLeidas[5];
    FILE *arc;
    // Ingresar datos en persona
    for(int i = 0; i < 5; i++){
        ingresarPersona(&persona[i]);
    }
    
    arc = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\10_11_2025\\archivito.bin", "wb");
    
    fwrite(&persona, sizeof(datosP), 5, arc);
    fclose(arc);
    
    arc = fopen("C:\\Users\\mario\\Documents\\CETI\\Ingenieria\\Programacion_Ingenieria\\Programacion_Estructurada\\Parcial_3\\10_11_2025\\archivito.bin", "rb");
    
    int t = fread(personasLeidas, sizeof(datosP), 5, arc);
    fclose(arc);

    printf("\n-------------------------------------------Datos del archivo----------------------------------------\n");
    for (int i = 0; i < t; i++) {
        mostrarPersona(personasLeidas[i]);
    }
}

void ingresarPersona(datosP *p){
    getchar();
    printf("\n\nNombre: ");
    fgets(p->name, 25, stdin);
    printf("Apellido: ");
    fgets(p->lastname, 25, stdin);
    printf("Correo: ");
    fgets(p->email, 30, stdin);
    printf("Edad: ");
    scanf(" %d", &p->age);
}
void mostrarPersona(datosP p) {
    printf("\nNombre: %s", p.name);
    printf("Apellido: %s", p.lastname);
    printf("Correo: %s", p.email);
    printf("Edad: %d\n", p.age);
}