using namespace std;

class Figura2D
{
protected:
    float area;
    float perimetro;

public:
    // Metodos get y set para area y perimetro
    float getArea();
    void setArea(float);
    float getPerimetro();
    void setPerimetro(float);

    /*
    Es necesario que existan los metodos en la clase Figura2D
    sin embargo, la implementación de cada método se debe de
    realizar en la clase hija.
    Por ese motivo se definen como métodos virtuales
    */
    virtual void calcular_area() {}
    virtual void calcular_perimetro() {}
};

float Figura2D::getArea() { return this->area; }
void Figura2D::setArea(float area) { this->area = area; }
float Figura2D::getPerimetro() { return this->perimetro; }
void Figura2D::setPerimetro(float perimetro) { this->perimetro = perimetro; }


void Figura2D::calcular_area(){
    cout << "PEPE" << endl;
}