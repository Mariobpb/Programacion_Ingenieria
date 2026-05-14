using namespace std;

class Pentagono : public Figura2D
{
private:
    float lado;
    float apotema;

public:
    void setLado(float);
    float getLado();
    void setApotema(float);
    float getApotema();

    void calcular_apotema();
    void calcular_area();
    void calcular_perimetro();
};

void Pentagono::setLado(float lado)
{
    this->lado = lado;
}
float Pentagono::getLado()
{
    return this->lado;
}
void Pentagono::setApotema(float apotema)
{
    this->apotema = apotema;
}
float Pentagono::getApotema()
{
    return this->apotema;
}
void Pentagono::calcular_apotema(){
    float theta = 360/(2*5);
    float radianes = theta*(3.1416/180);w
    setApotema(getLado()/(2*tan(radianes)));
}
void Pentagono::calcular_area()
{
    calcular_perimetro();
    calcular_apotema();
    setArea((getPerimetro()*getApotema())/2);
}
void Pentagono::calcular_perimetro()
{
    setPerimetro(5*getLado());
}