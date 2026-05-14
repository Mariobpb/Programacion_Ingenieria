using namespace std;

class MenuFiguras
{
public:
    Cuadrado objCuadrado;
    Triangulo objTriangulo;
    Figura2D *ptrObj;

public:
    void menu();
    void calcular_datos();
};

/*
En este metodo, el apuntador ptrObj se comporta de forma polimorfica,
dependiendo del objeto apuntado (Puede ser el objeto cuadrado o el
objeto triangulo) responde a los metodos calcular_area y calcular_perimetro
*/

void MenuFiguras::calcular_datos()
{
    ptrObj->calcular_area();
    ptrObj->calcular_perimetro();

    cout << endl;
    cout << "Area : " << ptrObj->getArea() << endl;
    cout << "Perimetro : " << ptrObj->getPerimetro() << endl;
    cout << endl;
}

void MenuFiguras::menu()
{
    int opcion;
    do
    {
        cout << "Figuras geommetricas en dos dimensiones" << endl;
        cout << "1. Cuadrado " << endl;
        cout << "2. Triangulo " << endl;
        cout << "3. Salir " << endl;
        cout << "Elige una opcion " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            float lado;
            cout << "Ingresa el lado del cuadrado : ";
            cin >> lado;
            objCuadrado.setLado(lado);
            ptrObj = &objCuadrado;
            calcular_datos();
            break;

        case 2:
            float base, altura;
            cout << "Ingresa la base del triangulo : ";
            cin >> base;
            cout << "Ingresa la altura del triangulo : ";
            cin >> altura;
            objTriangulo.setBase(base);
            objTriangulo.setAltura(altura);
            ptrObj = &objTriangulo;
            calcular_datos();
            break;
        case 3:
            break;
        default:
            cout << "Opcion No valida" << endl;
            break;
        }
    } while (opcion != 3);
}