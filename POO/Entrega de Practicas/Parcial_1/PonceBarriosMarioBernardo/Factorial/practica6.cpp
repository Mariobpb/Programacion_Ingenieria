#include <iostream>
using namespace std;

class Factorial {
    private:
        int numero;
        int factorial;
    public:
        int getNumero();
        void setNumero(int numero);
        int getFactorial();
        void setFactorial(int factorial);
        void leerNumero();
        void obtenerFactorial();
};

int Factorial::getNumero(){
    return this->numero;
}
void Factorial::setNumero(int numero){
    this->numero = numero;
}
int Factorial::getFactorial(){
    return this->factorial;
}
void Factorial::setFactorial(int factorial){
    this->factorial = factorial;
}
void Factorial::leerNumero(){
    int num;
    cout << "Ingresa un numero entero:  ";
    cin >> num;
    setNumero(num);
}
void Factorial::obtenerFactorial(){
    int factorial = 1;
    for(int i = 1; i <= getNumero(); i++){
        factorial *= i;
    }
    setFactorial(factorial);
    cout << getNumero() << "! = " << getFactorial() << endl;
}

int main(){
    Factorial f;
    f.leerNumero();
    f.obtenerFactorial();

    return 0;
}