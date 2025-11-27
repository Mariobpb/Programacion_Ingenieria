/*
25310234 - Mario Bernardo Ponce Barrios

crear una lista de personas, las cuales deben tener como datos personales:
nombre
correo
edad
registro

generar una buscqueda de acuerdo a una de las variables anteriores y mostrar todas las coincidencias.

hacerlo el ejercicio mediante estructuras
*/

#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 15

typedef struct {
    char nombre[50];
    char correo[50];
    int edad;
    int registro;
} Persona;

void ingresarPersona(Persona *p);
void mostrarLista(Persona *lista, int n);
void buscarPorNombre(Persona *lista, int n);
void buscarPorCorreo(Persona *lista, int n);
void buscarPorEdad(Persona *lista, int n);
void buscarPorRegistro(Persona *lista, int n);

int main() {

    Persona personas[MAX_PERSONAS];
    int opcion;
    
    for (int i = 0; i < MAX_PERSONAS; i++) {
        printf("\nPersona #%d\n", i + 1);
        ingresarPersona(&personas[i]);
    }

    do {
        printf("\n\n1. Mostrar lista completa\n");
        printf("2. Buscar por nombre\n");
        printf("3. Buscar por correo\n");
        printf("4. Buscar por edad\n");
        printf("5. Buscar por registro\n");
        printf("0. Salir\nOpción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                mostrarLista(personas, MAX_PERSONAS);
                break;
            case 2:
                buscarPorNombre(personas, MAX_PERSONAS);
                break;
            case 3:
                buscarPorCorreo(personas, MAX_PERSONAS);
                break;
            case 4:
                buscarPorEdad(personas, MAX_PERSONAS);
                break;
            case 5:
                buscarPorRegistro(personas, MAX_PERSONAS);
                break;
        }

    } while(opcion != 0);

    return 0;
}

void ingresarPersona(Persona *p) {
    printf("Nombre: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Correo: ");
    fgets(p->correo, 50, stdin);
    p->correo[strcspn(p->correo, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &p->edad);
    getchar();

    printf("Registro: ");
    scanf("%d", &p->registro);
    getchar();
}

void mostrarLista(Persona *lista, int n) {
    printf("\n------------------- LISTA DE PERSONAS -------------------\n");
    for (int i = 0; i < n; i++) {
        printf("\nNombre: %s", lista[i].nombre);
        printf("\nCorreo: %s", lista[i].correo);
        printf("\nEdad: %d", lista[i].edad);
        printf("\nRegistro: %d\n", lista[i].registro);
    }
}

void buscarPorNombre(Persona *lista, int n) {
    char nombreBuscar[50];
    printf("Nombre a buscar: ");
    fgets(nombreBuscar, 50, stdin);
    nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i].nombre, nombreBuscar) == 0) {
            printf("\nEncontrado:\nNombre: %s\nCorreo: %s\nEdad: %d\nRegistro: %d\n", lista[i].nombre, lista[i].correo, lista[i].edad, lista[i].registro);
            found = 1;
        }
    }
    if (!found) printf("No encontrado.\n");
}

void buscarPorCorreo(Persona *lista, int n) {
    char correoBuscar[50];
    printf("Correo a buscar: ");
    fgets(correoBuscar, 50, stdin);
    correoBuscar[strcspn(correoBuscar, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i].correo, correoBuscar) == 0) {
            printf("\nEncontrado:\nNombre: %s\nCorreo: %s\nEdad: %d\nRegistro: %d\n", lista[i].nombre, lista[i].correo, lista[i].edad, lista[i].registro);
            found = 1;
        }
    }
    if (!found) printf("No encontrado.\n");
}

void buscarPorEdad(Persona *lista, int n) {
    int edadBuscar;
    printf("Edad a buscar: ");
    scanf("%d", &edadBuscar);
    getchar();

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i].edad == edadBuscar) {
            printf("\nNombre: %s\nCorreo: %s\nEdad: %d\nRegistro: %d\n", lista[i].nombre, lista[i].correo, lista[i].edad, lista[i].registro);
            found = 1;
        }
    }
    if (!found) printf("No encontrado.\n");
}

void buscarPorRegistro(Persona *lista, int n) {
    int regBuscar;
    printf("Registro a buscar: ");
    scanf("%d", &regBuscar);
    getchar();

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i].registro == regBuscar) {
            printf("\nEncontrado:\nNombre: %s\nCorreo: %s\nEdad: %d\nRegistro: %d\n", lista[i].nombre, lista[i].correo, lista[i].edad, lista[i].registro);
            found = 1;
        }
    }
    if (!found) printf("No encontrado.\n");
}
