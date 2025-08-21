/*
Escribir un programa que pida por teclado los tres coeficientes (a, b y c) de la ecuación ax²+bx+c=0 y calcule las dos soluciones suponiendo que ambas sean reales (es decir que la raíz sea positiva).
Nota: x₁,₂ = (–b ± sqrt(b²–4ac)) / 2a.
sqrt es una función que devuelve la raíz cuadrada, para poder invocarla es necesario poner en la cabecera del programa: #include <math.h>
*/

#include <stdio.h>
#include <math.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Ingrese los valores de:\na: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    float x1, x2;

    int discriminante = (b*b)-(4*a*c);
    if (discriminante < 0){
        printf("El resultado no es un número real");
    } else {
        x1 = ((b*-1) + sqrt(discriminante)) / (2*a);
        x2 = ((b*-1) - sqrt(discriminante)) / (2*a);
        printf("Resultados:\nx1 = %.4f\nx2 = %.4f", x1, x2);
    }

    return 0;
}
