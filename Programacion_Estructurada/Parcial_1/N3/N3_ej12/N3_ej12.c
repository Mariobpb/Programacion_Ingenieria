/*
Ejercicio 12: Arrays multidimensionales. Rectas en el plano.
Se quiere representar rectas en un plano de números enteros. El plano será un array de
100x100 caracteres. El programa pedirá que se introduzcan los tres coeficientes
(números enteros) de una recta de la forma ax+by+c=0, representará los puntos de la
recta como asteriscos en la matriz, y presentará por pantalla dicha matriz.
*/

#include <stdio.h>

int resolverX(float a, float b, float c, float y);

int main()
{
    char plano[100][100];
    float a, b, c;

    printf("Introduce los siguientes valores:\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    for (int y = 99; y >= 0; y--)
    {
        int xR = resolverX(a, b, c, y-50);
        for (int x = 0; x < 100; x++)
        {
            if (y != 50)
                plano[x][y] = ' ';
            else
                plano[x][y] = '-';
            if (x == 50)
                plano[x][y] = '|';
            if (x == xR+50)
                plano[x][y] = '*';
        }
    }
    printf("\nLa ecuación quedó de la siguiente manera:\n%.2fx+%.2fy+%.2f=0\n", a, b, c);
    for (int y = 99; y >= 0; y--)
    {
        for (int x = 0; x < 100; x++)
        {
            printf("%c", plano[x][y]);
        }
        printf("\n");
    }

    return 0;
}

int resolverX(float a, float b, float c, float y)
{
    return (-((b * y) + c)) / a;
}