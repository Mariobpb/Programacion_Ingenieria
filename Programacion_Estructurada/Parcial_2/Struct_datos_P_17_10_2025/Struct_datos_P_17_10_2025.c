#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[50];
    char lastName[50];
    char email[50];
    int reg;
} DP;

void ingresarEmail(DP *);
void ingresarName(DP *);
void ingresarLastName(DP *);
void ingresarReg(DP *);
void limpiarEspacios(char *);
int verificarCaracteresAlf(char *);
int verificarCaracteresNum(char *);
void cambiarCadenaMinusculas(char *);
void agregarLista2(DP *, DP *);
void imprimirDP(DP *);
void mostrarLista(DP *);
void buscarName(DP *);
void buscarEmail(DP *);
void buscarReg(DP *);

int main()
{
    int opcion = 0;
    DP lista[15], lista2[15], *p, *p2;
    for (int i = 0; i < 15; i++)
        lista2[i].reg = -1;
    p = &lista[0];
    for (int i = 0; i < 15; i++)
    {
        ingresarEmail(p);
        ingresarName(p);
        ingresarLastName(p);
        ingresarReg(p);
        p++;
    }
    p = &lista[0];
    p2 = &lista2[0];
    agregarLista2(p, p2);
    do
    {
        p = &lista[0];
        p2 = &lista2[0];
        printf("\nQué desea hacer?\n1-Mostrar lista\n2-Buscar por nombre\n3-Buscar por correo\n4-Buscar por registro\n5-Mostrar lista de apellidos repetidos\n0-Salir\n");
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
        case 5:
            mostrarLista(p2);
            break;
        default:
            break;
        }
    } while (opcion != 0);

    return 0;
}

void ingresarEmail(DP *p)
{
    char aux[50];
    do
    {
        printf("Email: ");
        fgets(aux, 50, stdin);
        limpiarEspacios(aux);
        cambiarCadenaMinusculas(aux);
    } while (!verificarCaracteresAlf(aux));
    strcpy(p->email, aux);
    printf("\n\n|%s| Tabien\n\n", aux);
}
void ingresarName(DP *p)
{
    printf("Nombre: ");
    fgets(p->name, 50, stdin);
    limpiarEspacios(p->name);
}
void ingresarLastName(DP *p)
{
    printf("Apellido: ");
    fgets(p->lastName, 50, stdin);
    limpiarEspacios(p->lastName);
}
void ingresarReg(DP *p)
{
    printf("Registro: ");
    scanf("%d", &p->reg);
    getchar();
}
void limpiarEspacios(char *c)
{
    int i = 0, j = 0;
    while (c[i] != '\n' && c[i] == ' ')
        i++;
    while (c[i] != '\n' && c[i] != ' ')
        c[j++] = c[i++];
    c[j] = '\0';
}
int verificarCaracteresAlf(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        printf("\nRevisando: %c", c[i]);
        if (!(c[i] >= 'a' && c[i] >= 'z'))
            return 0;
        i++;
    }
    return 1;
}
int verificarCaracteresNum(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        if (!(c[i] >= '0' && c[i] >= '9'))
            return 0;
        i++;
    }
    return 1;
}
void cambiarCadenaMinusculas(char *c)
{
    for (int i = 0; c[i] != '\0' && i < 50; i++)
        c[i] = tolower(c[i]);
}
void agregarLista2(DP *p, DP *p2)
{
    int iLista2 = 0;
    char temp1[50], temp2[50];
    for (int i = 0; i < 15; i++)
    {
        int repetido = 0;
        strcpy(temp1, p[i].lastName);
        cambiarCadenaMinusculas(temp1);
        for (int j = 0; j < 15; j++)
        {
            if (i != j)
            {
                strcpy(temp2, p[j].lastName);
                cambiarCadenaMinusculas(temp2);
                if (strcmp(temp1, temp2) == 0)
                {
                    repetido = 1;
                    break;
                }
            }
        }
        if (repetido)
        {
            p2[iLista2] = p[i];
            iLista2++;
        }
    }
}
void imprimirDP(DP *p)
{
    printf("\nRegistro: %d", p->reg);
    printf("\nNombre: %s", p->name);
    printf("\nApellido: %s", p->lastName);
    printf("\nCorreo: %s\n", p->email);
}
void mostrarLista(DP *p)
{
    for (int i = 0; i < 15; i++)
    {
        if (p->reg != -1)
            imprimirDP(p);
        p++;
    }
}
void buscarName(DP *p)
{
    char name[50];
    printf("Ingrese el nombre a buscar: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < 15; i++)
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
    char email[50];
    printf("Ingrese el correo a buscar: ");
    fgets(email, 50, stdin);
    email[strcspn(email, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < 15; i++)
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
    for (int i = 0; i < 15; i++)
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