#include <iostream>
using namespace std;

class EstacionAño
{
private:
    int mes;

public:
    int getMes();
    void setMes(int mes);
    void leerMes();
    void evaluarMes();
};

int EstacionAño::getMes()
{
    return this->mes;
}
void EstacionAño::setMes(int mes)
{
    this->mes = mes;
}
void EstacionAño::leerMes()
{
    int mes;
    bool verificado = false;
    while (!verificado)
    {
        cout << "Ingresa un numero de mes:  " << endl;
        cin >> mes;
        if (mes >= 1 && mes <= 12)
            verificado = true;
        else
            cout << "el numero debe ser entre 1 y 12" << endl;
    }
    setMes(mes);
}
void EstacionAño::evaluarMes()
{
    cout << "La temporada del anio es: ";
    if (getMes() == 12 || (getMes() >= 1 && getMes() <= 2))
        cout << "Invierno";
    else if (getMes() >= 3 && getMes() <= 5)
        cout << "Primavera";
    else if (getMes() >= 6 && getMes() <= 8)
        cout << "Verano";
    else
        cout << "Otonio";
}

int main()
{
    EstacionAño ea;
    ea.leerMes();
    ea.evaluarMes();
    return 0;
}