using namespace std;

class Rectangulo : public Figura2D
{
private:
    float base;
    float altura;

public:
    void setBase(float);
    float getBase();
    void setAltura(float);
    float getAltura();

    void calcular_area();
    void calcular_perimetro();
};

void Rectangulo::setBase(float base)
{
    this->base = base;
}
float Rectangulo::getBase()
{
    return this->base;
}
void Rectangulo::setAltura(float altura)
{
    this->altura = altura;
}
float Rectangulo::getAltura()
{
    return this->altura;
}
void Rectangulo::calcular_area()
{
    setArea(getBase()*getAltura());
}
void Rectangulo::calcular_perimetro()
{
    setPerimetro(2*(getBase()+getAltura()));
}