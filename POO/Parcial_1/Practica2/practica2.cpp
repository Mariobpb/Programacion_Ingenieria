#include <iostream>
using namespace std;

class NumeroPositivoNegativo
{
private:
    int numero;

public:
    int getNumero();
    void setNumero(int numero);
    void leerNumero();
    void evaluarNumero();
};

int NumeroPositivoNegativo::getNumero()
{
    return this->numero;
}
void NumeroPositivoNegativo::setNumero(int numero)
{
    this->numero = numero;
}
void NumeroPositivoNegativo::leerNumero()
{
    int num;
    cout << "Ingresa un numero entero:  ";
    cin >> num;
    setNumero(num);
}
void NumeroPositivoNegativo::evaluarNumero()
{
    cout << "El numero " << getNumero();
    if (getNumero() < 0)
    {
        cout << " es negativo" << endl;
    }
    else if (getNumero() > 0)
    {
        cout << " es positivo" << endl;
    }
    else
    {
        cout << " es cero" << endl;
    }
}

int main()
{
    NumeroPositivoNegativo npn;
    npn.leerNumero();
    npn.evaluarNumero();
    return 0;
}