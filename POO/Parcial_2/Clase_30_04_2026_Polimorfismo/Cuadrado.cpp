using namespace std;

class Cuadrado : public Figura2D
{
private:
    float lado;

public:
    // Metodos get y set para el lado
    float getLado();
    void setLado(float);

    void calcular_area();
    void calcular_perimetro();
};

float Cuadrado::getLado() { return this->lado; }
void Cuadrado::setLado(float lado) { this->lado = lado; }
// Se define la forma en que se calcula el area de un cuadrado
void Cuadrado::calcular_area()
{
    setArea(getLado() * getLado());
}
// Se define la forma en que se calcula el perimetro de un cuadrado
void Cuadrado::calcular_perimetro()
{
    setPerimetro(4 * getLado());
}