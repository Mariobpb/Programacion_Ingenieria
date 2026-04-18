#include <iostream>
using namespace std;

class Sobrecarga
{
private:
    int num1;
    int num2;
    int num3;

public:
    void setNum1(int);
    void setNum2(int);
    void setNum3(int);

    int getNum1();
    int getNum2();
    int getNum3();

    float sumarNumeros();
    float sumarNumeros(int x, int y);
    float sumarNumeros(float x, float y);
};

float Sobrecarga::sumarNumeros()
{
    return getNum1() + getNum2() + getNum3();
}
float Sobrecarga::sumarNumeros(int x, int y)
{
    return x + y;
}
float Sobrecarga::sumarNumeros(float x, float y)
{
    return x + y;
}

void Sobrecarga::setNum1(int num1) { this->num1 = num1; }
void Sobrecarga::setNum2(int num2) { this->num2 = num2; }
void Sobrecarga::setNum3(int num3) { this->num3 = num3; }

int Sobrecarga::getNum1() { return this->num1; }
int Sobrecarga::getNum2() { return this->num2; }
int Sobrecarga::getNum3() { return this->num3; }

main()
{
    Sobrecarga obj;
    obj.setNum1(10);
    obj.setNum2(20);
    obj.setNum3(30);

    cout << endl << "Suma de Atributos: " << obj.sumarNumeros() << endl;
    cout << endl << "Suma de 2 Atributos: " << obj.sumarNumeros(obj.getNum1(), obj.getNum3()) << endl;
    cout << endl << "Suma de 2 Atributos: " << obj.sumarNumeros(obj.getNum2(), obj.getNum3()) << endl;
    cout << endl << "Suma de 2 Numeros: " << obj.sumarNumeros(25, 50) << endl;
    cout << endl << "Suma de 2 Numeros: " << obj.sumarNumeros(4.5f, 2.3f) << endl;

    return 0;
}