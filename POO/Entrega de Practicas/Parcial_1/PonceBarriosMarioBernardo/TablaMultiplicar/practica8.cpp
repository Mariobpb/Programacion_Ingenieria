#include <iostream>
using namespace std;

class TablaMultiplicar
{
private:
    int numero;

public:
    int getNumero();
    void setNumero(int numero);
    void leerNumero();
    void obtenerTablaMultiplicar();
};

int TablaMultiplicar::getNumero()
{
    return this->numero;
}
void TablaMultiplicar::setNumero(int numero)
{
    this->numero = numero;
}
void TablaMultiplicar::leerNumero()
{
    int numero;
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    setNumero(numero);
}
void TablaMultiplicar::obtenerTablaMultiplicar()
{
    cout << "Tabla del " << getNumero() << ":" << endl;
    for (int i = 1; i <= 10; i++)
        cout << getNumero() << " x " << i << " = " << getNumero() * i << endl;
}

int main()
{
    TablaMultiplicar tm;
    tm.leerNumero();
    tm.obtenerTablaMultiplicar();

    return 0;
}