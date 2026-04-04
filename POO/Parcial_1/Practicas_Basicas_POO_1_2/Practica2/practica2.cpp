#include <string>
#include <iostream>
using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAnio();
    void setAnio(int anio);

    void leerFecha();
    int validarFecha(int dia, int mes, int anio);
    void imprimirFechaCorta();
    void imprimirFechaLarga();
};

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->anio = 1;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    
    if(!validarFecha(dia, mes, anio)){
        this->dia = 1;
        this->mes = 1;
        this->anio = 1;
    } else {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    /*
    if (dia >= 1 && dia <= 31)
        this->dia = dia;
    else
        this->dia = 1;
    if (mes >= 1 && mes <= 12)
        this->mes = mes;
    else
        this->mes = 1;
    if (anio >= 0)
        this->anio = anio;
    else
        this->anio = 1;
    */
}
int Fecha::getDia()
{
    return this->dia;
}
void Fecha::setDia(int dia)
{
    this->dia = dia;
}
int Fecha::getMes()
{
    return this->mes;
}
void Fecha::setMes(int mes)
{
    this->mes = mes;
}
int Fecha::getAnio()
{
    return this->anio;
}
void Fecha::setAnio(int anio)
{
    this->anio = anio;
}

void Fecha::leerFecha()
{
    int dia, mes, anio;
    do
    {
        cout << "Ingrese los siguientes datos:\nDia: ";
        cin >> dia;
        setDia(dia);
        cout << "Mes: ";
        cin >> mes;
        setMes(mes);
        cout << "Anio: ";
        cin >> anio;
        setAnio(anio);
        if (!validarFecha(dia, mes, anio))
            cout << "Debe ingresar una fecha valida" << endl;
    } while (!validarFecha(dia, mes, anio));
}
int Fecha::validarFecha(int dia, int mes, int anio)
{
    int esBisiesto = 0;
    int diaLimite = 0;

    if (anio < 1)
        return 0;
    if (mes < 1 || mes > 12)
        return 0;

    if (anio % 4 == 0)
    {
        if (anio % 100 != 0){
            esBisiesto = 1;
        }
        else if (anio % 400 == 0)
            esBisiesto = 1;
    }

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        diaLimite = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        diaLimite = 30;
        break;
    case 2:
        if (esBisiesto)
            diaLimite = 29;
        else
            diaLimite = 28;
        break;
    }

    if (dia < 1 || dia > diaLimite)
        return 0;
    return 1;
}
/*
int Fecha::validarFecha()
{
    int esBisiesto = 0;
    int diaLimite = 0;

    if (getAnio() < 1)
        return 0;
    if (getMes() < 1 || getMes() > 12)
        return 0;

    if (getAnio() % 4 == 0)
    {
        if (getAnio() % 100 != 0)
            esBisiesto = 1;
        else if (getAnio() % 400 == 0)
            esBisiesto = 1;
    }

    switch (getMes())
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        diaLimite = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        diaLimite = 30;
        break;
    case 2:
        if (esBisiesto)
            diaLimite = 29;
        else
            diaLimite = 28;
        break;
    }

    if (getDia() < 1 || getDia() > diaLimite)
        return 0;
    return 1;
}*/
void Fecha::imprimirFechaCorta()
{
    cout << "Fecha ingresada (corta):\t" << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}
void Fecha::imprimirFechaLarga()
{
    string mesStr = "";
    switch (getMes())
    {
    case 1:
        mesStr = "Enero";
        break;
    case 2:
        mesStr = "Febrero";
        break;
    case 3:
        mesStr = "Marzo";
        break;
    case 4:
        mesStr = "Abril";
        break;
    case 5:
        mesStr = "Mayo";
        break;
    case 6:
        mesStr = "Junio";
        break;
    case 7:
        mesStr = "Julio";
        break;
    case 8:
        mesStr = "Agosto";
        break;
    case 9:
        mesStr = "Septiembre";
        break;
    case 10:
        mesStr = "Octubre";
        break;
    case 11:
        mesStr = "Noviembre";
        break;
    case 12:
        mesStr = "Diciembre";
        break;
    }
    cout << "Fecha ingresada (larga):\t" << getDia() << " de " << mesStr << " de " << getAnio() << endl;
}

int main()
{
    Fecha objFecha1;
    objFecha1.leerFecha();
    objFecha1.imprimirFechaCorta();
    objFecha1.imprimirFechaLarga();

    Fecha objFecha2(3, 1, 2005);
    objFecha2.imprimirFechaCorta();
    objFecha2.imprimirFechaLarga();
}