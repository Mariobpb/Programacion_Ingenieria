using namespace std;

class Cuadrado : public Figura2D {
private:
  float lado;

public:
  //Metodos get y set para el lado
  void setLado(float);
  float getLado();

  void calcular_area();
  void calcular_perimetro();
};

void Cuadrado::setLado(float lado){ 
  this->lado = lado;
}
float Cuadrado::getLado(){ 
  return this->lado; 
}
//Se define la forma en que se calcula el area de un cuadrado
void Cuadrado::calcular_area(){
    setArea( getLado() * getLado() );
}
//Se define la forma en que se calcula el perimetro de un cuadrado
void Cuadrado::calcular_perimetro(){
    setPerimetro( 4 * getLado() );
  }