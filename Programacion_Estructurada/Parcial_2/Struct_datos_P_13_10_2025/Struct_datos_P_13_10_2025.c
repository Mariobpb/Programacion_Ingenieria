#include <stdio.h>
#include <string.h>

#define DPMAX 10
#define charMAX 50

typedef struct
{
    char email[charMAX];
    char name[charMAX];
    int reg;
} DP;

void ingresarEmail(DP *);
void ingresarName(DP *);
void ingresarReg(DP *);
void imprimirDP(DP *);
void mostrarLista(DP *);
void buscarName(DP *);
void buscarEmail(DP *);
void buscarReg(DP *);

int main()
{
    int opcion = 0;
    DP lista[DPMAX], *p;
    p = &lista[0];
    for (int i = 0; i < DPMAX; i++)
    {
        ingresarEmail(p);
        ingresarName(p);
        ingresarReg(p);
        p++;
    }
    do
    {
        p = &lista[0];
        printf("\nQué desea hacer?\n1-Mostrar lista completa\n2-Buscar por nombre\n3-Buscar por correo\n4-Buscar por registro\n0-Salir\n");
        scanf("%d", &opcion);
        getchar();
        switch (opcion)
        {
        case 0:
            break;
        case 1:
            mostrarLista(p);
            break;
        case 2:
            buscarName(p);
            break;
        case 3:
            buscarEmail(p);
            break;
        case 4:
            buscarReg(p);
            break;
        default:
            break;
        }
    } while (opcion != 0);
    
    return 0;
}

void ingresarEmail(DP *p)
{
    printf("Email: ");
    fgets(p->email, charMAX, stdin);
    p->email[strcspn(p->email, "\n")] = 0;
}
void ingresarName(DP *p)
{
    printf("Nombre: ");
    fgets(p->name, charMAX, stdin);
    p->name[strcspn(p->name, "\n")] = 0;
}
void ingresarReg(DP *p)
{
    printf("Registro: ");
    scanf("%d", &p->reg);
    getchar();
}
void imprimirDP(DP *p)
{
    printf("\nRegistro: %d", p->reg);
    printf("\nNombre: %s", p->name);
    printf("\nCorreo: %s\n", p->email);
}
void mostrarLista(DP *p)
{
    for (int i = 0; i < DPMAX; i++)
    {
        imprimirDP(p);
        p++;
    }
}
void buscarName(DP *p)
{
    char name[charMAX];
    printf("Ingrese el nombre a buscar: ");
    fgets(name, charMAX, stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < DPMAX; i++)
    {
        if (strcmp(p->name, name) == 0)
        {
            imprimirDP(p);
            found = 1;
        }
        p++;
    }
    if (!found)
        printf("Persona no encontrada\n");
}
void buscarEmail(DP *p)
{
    char email[charMAX];
    printf("Ingrese el correo a buscar: ");
    fgets(email, charMAX, stdin);
    email[strcspn(email, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < DPMAX; i++)
    {
        if (strcmp(p->email, email) == 0)
        {
            imprimirDP(p);
            found = 1;
        }
        p++;
    }
    if (!found)
        printf("Persona no encontrada\n");
}
void buscarReg(DP *p)
{
    int reg;
    printf("Ingrese el registro a buscar: ");
    scanf("%d", &reg);
    getchar();
    int found = 0;
    for (int i = 0; i < DPMAX; i++)
    {
        if (p->reg == reg)
        {
            imprimirDP(p);
            found = 1;
        }
        p++;
    }
    if (!found)
        printf("Persona no encontrada\n");
}