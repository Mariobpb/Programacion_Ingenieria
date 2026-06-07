using namespace std;

class MenuFiguras
{
public:
  Cuadrado objCuadrado;
  Triangulo objTriangulo;
  Circulo objCirculo;
  Rectangulo objRectangulo;
  Pentagono objPentagono;
  Figura2D *ptrObj;

public:
  void menu();
  void calcular_datos();
};

// En este metodo, el apuntador ptrObj se comporta de forma
//  polimorfica, dependiende del objeto apuntado
//(Puede ser el objeto cuadrado o el objeto triangulo)
//  responde a los metodos calcular_area y calcular_perimetro

void MenuFiguras::calcular_datos()
{
  ptrObj->calcular_area();
  ptrObj->calcular_perimetro();

  cout << endl;
  cout << "Area : " << ptrObj->getArea() << " u^2" << endl;
  cout << "Perimetro :" << ptrObj->getPerimetro() << " u" << endl;
  cout << endl;
}

void MenuFiguras::menu()
{
  float lado, base, altura, radio;
  int opcion;
  do
  {
    cout << "Figuras geometricas en dos dimensiones" << endl;
    cout << "1. Cuadrado " << endl;
    cout << "2. Triangulo" << endl;
    cout << "3. Circulo" << endl;
    cout << "4. Rectangulo" << endl;
    cout << "5. Pentagono" << endl;
    cout << "6. Salir" << endl;
    cout << "Elige una opcion " << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      cout << "Ingresa el Lado del cuadrado :";
      cin >> lado;
      objCuadrado.setLado(lado);
      ptrObj = &objCuadrado;
      calcular_datos();
      break;
    case 2:
      cout << "Ingresa la base del triangulo :";
      cin >> base;
      cout << "Ingresa la altura del triangulo :";
      cin >> altura;
      objTriangulo.setBase(base);
      objTriangulo.setAltura(altura);
      ptrObj = &objTriangulo;
      calcular_datos();
      break;
    case 3:
      cout << "Ingresa el radio del circulo :";
      cin >> radio;
      objCirculo.setRadio(radio);
      ptrObj = &objCirculo;
      calcular_datos();
      break;
    case 4:
      cout << "Ingresa la base del rectangulo :";
      cin >> base;
      cout << "Ingresa la altura del rectangulo :";
      cin >> altura;
      objRectangulo.setBase(base);
      objRectangulo.setAltura(altura);
      ptrObj = &objRectangulo;
      calcular_datos();
      break;
    case 5:
      cout << "Ingresa el lado del pentagono :";
      cin >> lado;
      objPentagono.setLado(lado);
      ptrObj = &objPentagono;
      calcular_datos();
      break;
    case 6:
      break;
    default:
      cout << "Opcion No valida" << endl;
    }
  } while (opcion != 6);
}
