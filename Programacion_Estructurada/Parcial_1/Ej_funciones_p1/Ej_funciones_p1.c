#include <stdio.h>

void ingresarCalis(int* c1, int* c2, int* c3);
float promediar(int c1, int c2, int c3);
int evaluarPromedio(float p);
void imprimirPrm(float R);


int main() {
    int c1, c2, c3;
    float R;
    ingresarCalis(&c1, &c2, &c3);
    R = promediar(c1, c2, c3);
    imprimirPrm(R);

    return 0;
}

void ingresarCalis(int* c1, int* c2, int* c3){
    printf("Ingrese parcial 1\n");
    scanf("%d", c1);
    printf("Ingrese parcial 2\n");
    scanf("%d", c2);
    printf("Ingrese parcial 3\n");
    scanf("%d", c3);
}
float promediar(int c1, int c2, int c3){
    return((c1+c2+c3)/3);
}
int evaluarPromedio(float p){
    if(p >= 70)
        return 1; //Aprobado
    return 0;
}
void imprimirPrm(float R){
    int s = evaluarPromedio(R); //status
    printf("Promedio: %.2f\n", R);
    if(s)
        printf("Aprobado");
    else
        printf("Reprobado");
}