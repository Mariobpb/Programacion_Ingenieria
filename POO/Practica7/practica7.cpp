#include <iostream>
using namespace std;

class NumerosComparados
{
private:
    int numero1;
    int numero2;
    int numero3;

public:
    int getNumero1();
    void setNumero1(int numero1);
    int getNumero2();
    void setNumero2(int numero2);
    int getNumero3();
    void setNumero3(int numero3);
    void leerNumeros();
    void obtenerNumeroCentral();
};

int NumerosComparados::getNumero1()
{
    return this->numero1;
}
void NumerosComparados::setNumero1(int numero1)
{
    this->numero1 = numero1;
}
int NumerosComparados::getNumero2()
{
    return this->numero2;
}
void NumerosComparados::setNumero2(int numero2)
{
    this->numero2 = numero2;
}
int NumerosComparados::getNumero3()
{
    return this->numero3;
}
void NumerosComparados::setNumero3(int numero3)
{
    this->numero3 = numero3;
}
void NumerosComparados::leerNumeros()
{
    int num1, num2, num3;
    cout << "Ingresa el numero 1:  ";
    cin >> num1;
    setNumero1(num1);
    cout << "Ingresa el numero 2:  ";
    cin >> num2;
    setNumero2(num2);
    cout << "Ingresa el numero 3:  ";
    cin >> num3;
    setNumero3(num3);
}
void NumerosComparados::obtenerNumeroCentral()
{
    cout << "El numero central es: ";
    if (getNumero1() < getNumero2() && getNumero2() < getNumero3())
        cout << getNumero2();
    else if (getNumero2() < getNumero1() && getNumero1() != getNumero3())
        cout << "Los tres numeros son diferentes";
    else
        cout << "Hay dos numeros iguales y uno diferente";
}

int main()
{
    NumerosComparados nc;
    nc.leerNumeros();
    nc.obtenerNumeroCentral();
    return 0;
}