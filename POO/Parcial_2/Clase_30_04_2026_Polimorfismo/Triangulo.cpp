using namespace std;

class Triangulo : public Figura2D
{
private:
    float base;
    float altura;

public:
    // Metodos get y set para base y altura
    float getBase();
    void setBase(float);
    float getAltura();
    void setAltura(float);

    void calcular_area();
    void calcular_perimetro();
};

float Triangulo::getBase() { return this->base; }
void Triangulo::setBase(float base) { this->base = base; }
float Triangulo::getAltura() { return this->altura; }
void Triangulo::setAltura(float altura) { this->altura = altura; }
// Se define la forma en que se calcula el area de un triangulo
void Triangulo::calcular_area()
{
    setArea((getBase() * getAltura()) / 2);
}
// Se define la forma en que se calcula el perimetro de un triangulo
void Triangulo::calcular_perimetro()
{
    //Se da por entendido que es un triángulo equilátero
    setPerimetro(3 * getBase());
}