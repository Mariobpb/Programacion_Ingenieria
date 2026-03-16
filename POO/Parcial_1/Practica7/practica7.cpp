#include <iostream>
using namespace std;

class NumeroCentral
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

int NumeroCentral::getNumero1()
{
    return this->numero1;
}
void NumeroCentral::setNumero1(int numero1)
{
    this->numero1 = numero1;
}
int NumeroCentral::getNumero2()
{
    return this->numero2;
}
void NumeroCentral::setNumero2(int numero2)
{
    this->numero2 = numero2;
}
int NumeroCentral::getNumero3()
{
    return this->numero3;
}
void NumeroCentral::setNumero3(int numero3)
{
    this->numero3 = numero3;
}
void NumeroCentral::leerNumeros()
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
void NumeroCentral::obtenerNumeroCentral()
{
    cout << "El numero central es: ";
    if ((getNumero1() < getNumero2() && getNumero2() < getNumero3())||(getNumero3() < getNumero2() && getNumero2() < getNumero1()))
        cout << getNumero2();
    else if ((getNumero2() < getNumero1() && getNumero1() < getNumero3())||(getNumero3() < getNumero1() && getNumero1() < getNumero2()))
        cout << getNumero1();
    else
        cout << getNumero3();
}

int main()
{
    NumeroCentral nc;
    nc.leerNumeros();
    nc.obtenerNumeroCentral();
    return 0;
}