#include <iostream>
#include <math.h>
#include "Figura2D.cpp"
#include "Cuadrado.cpp"
#include "Triangulo.cpp"
#include "Circulo.cpp"
#include "Rectangulo.cpp"
#include "Pentagono.cpp"
#include "MenuFiguras.cpp"

using namespace std;

int main(){
  MenuFiguras objeto;
  objeto.menu();
  return 0;
}
