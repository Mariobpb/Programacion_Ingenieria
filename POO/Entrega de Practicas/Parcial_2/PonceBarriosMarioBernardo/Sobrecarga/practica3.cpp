#include <iostream>
using namespace std;

class Calculos
{
private:
    double numero1;
    double numero2;
    double numero3;
    double resultado;

public:
    double getNumero1();
    double getNumero2();
    double getNumero3();
    double getResultado();

    void setNumero1(double);
    void setNumero2(double);
    void setNumero3(double);
    void setResultado(double);

    void leerDatos(double);
    void leerDatos(double, double);
    void leerDatos(double, double, double);

    double sumar(double, double);
    double sumar(double, double, double);

    double promedio(double, double);
    double promedio(double, double, double);

    void mostrarMenu();
};

double Calculos::getNumero1() { return this->numero1; }
double Calculos::getNumero2() { return this->numero2; }
double Calculos::getNumero3() { return this->numero3; }
double Calculos::getResultado() { return this->resultado; }

void Calculos::setNumero1(double numero1) { this->numero1 = numero1; }
void Calculos::setNumero2(double numero2) { this->numero2 = numero2; }
void Calculos::setNumero3(double numero3) { this->numero3 = numero3; }
void Calculos::setResultado(double resultado) { this->resultado = resultado; }

void Calculos::leerDatos(double numero1) { 
    setNumero1(numero1); 
}
void Calculos::leerDatos(double numero1, double numero2) { 
    setNumero1(numero1);
    setNumero2(numero2); 
}
void Calculos::leerDatos(double numero1, double numero2, double numero3) {
    setNumero1(numero1);
    setNumero2(numero2);
    setNumero3(numero3);
}

double Calculos::sumar(double numero1, double numero2){
    leerDatos(numero1, numero2);
    setResultado(getNumero1() + getNumero2());
    return getResultado();
}
double Calculos::sumar(double numero1, double numero2, double numero3){
    leerDatos(numero1, numero2, numero3);
    setResultado(getNumero1() + getNumero2() + getNumero3());
    return getResultado();
}

double Calculos::promedio(double numero1, double numero2){
    leerDatos(numero1, numero2);
    setResultado((getNumero1() + getNumero2()) / 2);
    return getResultado();
}
double Calculos::promedio(double numero1, double numero2, double numero3){
    leerDatos(numero1, numero2, numero3);
    setResultado((getNumero1() + getNumero2() + getNumero3()) / 3);
    return getResultado();
}

void Calculos::mostrarMenu()
{
    double n1, n2, n3;
    int opcion;
    do
    {
        cout << "\n\nCalculos Matematicos" << endl;
        cout << "\t1. Sumar dos numeros" << endl;
        cout << "\t2. Sumar tres numeros" << endl;
        cout << "\t3. Promedio de dos numeros" << endl;
        cout << "\t4. Promedio de tres numeros" << endl;
        cout << "\t5. Salir del sistema" << endl;
        cout << endl
             << "Elije una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;
            cout << endl << "Suma: " << sumar(n1, n2) << endl;
            break;
        case 2:
            cout << "\nIngrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;
            cout << "Ingrese el tercer numero: ";
            cin >> n3;
            cout << endl << "Suma: " << sumar(n1, n2, n3) << endl;
            break;
        case 3:
            cout << "\nIngrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;
            cout << endl << "Promedio: " << promedio(n1, n2) << endl;
            break;
        case 4:
            cout << "\nIngrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;
            cout << "Ingrese el tercer numero: ";
            cin >> n3;
            cout << endl << "Promedio: " << promedio(n1, n2, n3) << endl;
            break;
        case 5:
            cout << endl << "Adios :)";
            break;
        default:
            cout << endl << "Ingrese una opcion valida";
            break;
        }

    } while (opcion != 5);
}

int main()
{
    Calculos objCalculos;
    objCalculos.mostrarMenu();
}