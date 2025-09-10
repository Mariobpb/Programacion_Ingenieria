/*
Ejercicio 1: Cálculo de precios con descuento
Escribe un programa que pregunte el precio, el tanto por ciento de descuento, y te diga el precio con descuento.
Por ejemplo, si el precio que introduce el usuario es 300 y el descuento 20, el programa dirá que el precio final con descuento es de 240.
*/

#include <stdio.h>

int main() {
  float price = 0;
  int disc_percentage = 0;

  do {
    printf("Ingrese el precio del producto: ");
    scanf("%f", &price);
  } while(price < 0);

  do{
    printf("Ingrese el porcentaje de descuento del producto: ");
    scanf("%d", &disc_percentage);
  } while(disc_percentage < 0 || disc_percentage > 100);

  float result = price - ((price / 100) * (disc_percentage));

  printf("El precio con descuento es de: %.2f$", result);

  return 0;
}
