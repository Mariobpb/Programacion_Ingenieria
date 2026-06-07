#include <iostream>
using namespace std;

class Figura
{
private:
    float largo;
    float ancho;
    float alto;
    float volumen;

public:
    Figura();
    Figura(float largo, float ancho, float alto);

    float getLargo();
    void setLargo(float largo);
    float getAncho();
    void setAncho(float ancho);
    float getAlto();
    void setAlto(float alto);
    float getVolumen();
    void setVolumen(float volumen);

    void leerMedida();
    void imprimirMedidas();
    float obtenerVolumen();
};

Figura::Figura()
{
    this->largo = 1;
    this->ancho = 1;
    this->alto = 1;
}
Figura::Figura(float largo, float ancho, float alto)
{
    if (largo < 0)
        this->largo = 1;
    else
        this->largo = largo;
    if (ancho < 0)
        this->ancho = 1;
    else
        this->ancho = ancho;
    if (alto < 0)
        this->alto = 1;
    else
        this->alto = alto;
}

float Figura::getLargo()
{
    return this->largo;
}
void Figura::setLargo(float largo)
{
    this->largo = largo;
}
float Figura::getAncho()
{
    return this->ancho;
}
void Figura::setAncho(float ancho)
{
    this->ancho = ancho;
}
float Figura::getAlto()
{
    return this->alto;
}
void Figura::setAlto(float alto)
{
    this->alto = alto;
}
float Figura::getVolumen()
{
    return this->volumen;
}
void Figura::setVolumen(float volumen)
{
    this->volumen = volumen;
}

void Figura::leerMedida()
{
    float largo, ancho, alto;
    cout << "Ingrese largo: ";
    cin >> largo;
    setLargo(largo);
    cout << "Ingrese ancho: ";
    cin >> ancho;
    setAncho(ancho);
    cout << "Ingrese alto: ";
    cin >> alto;
    setAlto(alto);
}
void Figura::imprimirMedidas()
{
    setVolumen(obtenerVolumen());
    cout << "============= MEDIDAS =============" << endl;
    cout << "Largo: " << getLargo() << "\nAncho: " << getAncho() << "\nAlto: " << getAlto() << "\nVolumen: " << getVolumen() << endl;
}
float Figura::obtenerVolumen()
{
    return getLargo() * getAncho() * getAlto();
}

int main()
{
    cout << endl;
    Figura objFigura1;
    objFigura1.leerMedida();
    objFigura1.imprimirMedidas();

    Figura objFigura2(20, -15, 10);
    objFigura2.imprimirMedidas();

    return 0;
}