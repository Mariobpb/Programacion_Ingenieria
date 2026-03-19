#include <iostream>
using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int año;

public:
    Fecha();
    Fecha(int dia, int mes, int año);

    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAño();
    void setAño(int año);

    void leerFecha();
    int validarFecha();
    void imprimirFechaCorta();
    void imprimirFechaLarga();
};

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->año = 1;
}
Fecha::Fecha(int dia, int mes, int año)
{
    if (dia > 0 && dia < 32)
        this->dia = dia;
    else
        this->dia = 1;
    if (mes > 0 && mes < 13)
        this->mes = mes;
    else
        this->mes = 1;
    if (año >= 0)
        this->año = año;
    else
        this->año = 1;
}
int getDia();
void setDia(int dia);
int getMes();
void setMes(int mes);
int getAño();
void setAño(int año);

void leerFecha();
int validarFecha();
void imprimirFechaCorta();
void imprimirFechaLarga();