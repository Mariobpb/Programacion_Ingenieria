#include <stdio.h>

typedef struct
{
    char name[50];
    char email[50];
    char registro[12];
} datos_P;

datos_P ingresarDatos(void);
void reemplazarEDtoNull(char *cad);
int verificarEmail(char *em);
int verificarReg(char *r);
void mostrarDatos(datos_P p);

int main()
{
    datos_P grupo[30];
    for (int i = 0; i < 30; i++)
        grupo[i] = ingresarDatos();
    for (int i = 0; i < 30; i++)
        mostrarDatos(grupo[i]);

    return 0;
}
datos_P ingresarDatos(void)
{
    datos_P T;
    printf("nombre: ");
    fgets(T.name, 50, stdin);
    reemplazarEDtoNull(T.name);
    do
    {
        printf("email: ");
        fgets(T.email, 50, stdin);
        reemplazarEDtoNull(T.email);
    } while (!verificarEmail(T.email));
    do
    {
        printf("registro: ");
        fgets(T.registro, 50, stdin);
        reemplazarEDtoNull(T.registro);
    } while (!verificarReg(T.registro));

    return T;
}
void reemplazarEDtoNull(char *cad)
{
    int i = 0;
    while (cad[i] != '\n')
        i++;
    cad[i] = '\0';
}
int verificarEmail(char *em)
{
    int i = 0;
    while (em[i] != '\0')
    {
        if (em[i] == '@')
            return 1;
        i++;
    }
    return 0;
}
int verificarReg(char *r)
{
    int i = 0;
    do
    {
        if ((r[i] < '0') || (r[i] > '9'))
            return 0;
        i++;
    } while (r[i] != '\0');
    return 1;
}
void mostrarDatos(datos_P p)
{
    printf("\nNombre: %s\nEdad: %s\nRegistro: %s\n", p.name, p.email, p.registro);
}