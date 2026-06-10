using namespace std;

class Circulo : public Figura2D
{
private:
    float radio;

public:
    void setRadio(float);
    float getRadio();

    void calcular_area();
    void calcular_perimetro();
};

void Circulo::setRadio(float radio)
{
    this->radio = radio;
}
float Circulo::getRadio()
{
    return this->radio;
}
void Circulo::calcular_area()
{
    setArea(3.1416 * (getRadio() * getRadio()));
}
void Circulo::calcular_perimetro()
{
    setPerimetro(3.1416 * (2 * getRadio()));
}