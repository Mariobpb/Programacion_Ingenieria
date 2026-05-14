using namespace std;

class Triangulo : public Figura2D {
private :
    float base,altura;

public :
  //Metodos get y set para base y altura
  void setBase(float);
  float getBase();
  void setAltura(float);  
  float getAltura();

  void calcular_area();
  void calcular_perimetro();
};

void Triangulo::setBase(float base){ 
  this->base = base;
}
float Triangulo::getBase(){ 
  return this->base; 
}
void Triangulo::setAltura(float altura){ 
  this->altura = altura;
}
float Triangulo::getAltura(){ 
  return this->altura; 
}

//Se define la forma en que se calcula el area de un triangulo
void Triangulo::calcular_area(){
    setArea( getBase() * getAltura() / 2 );
}

//Se define la forma en que se calcula el perimetro de un triangulo
void Triangulo::calcular_perimetro(){
    //Se da por entendido que es un triángulo equilatero
    setPerimetro( 3 * getBase() );
}