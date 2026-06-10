#include <iostream>
using namespace std;

class SecuenciaNumeros {
    private:
        int numero;
    public:
        int getNumero();
        void setNumero(int numero);
        void leerNumero();
        void evaluarNumero();
};

int SecuenciaNumeros::getNumero(){
    return this->numero;
}
void SecuenciaNumeros::setNumero(int numero){
    this->numero = numero;
}
void SecuenciaNumeros::leerNumero(){
    int num;
    cout << "Ingresa un numero entero:  ";
    cin >> num;
    setNumero(num);
}
void SecuenciaNumeros::evaluarNumero(){
    while(getNumero() < 10 || getNumero() > 15){
        cout << "Debe ingresar un numero entero entre 10 y 15 para salir" << endl;
        leerNumero();
    }
}

int main(){
    SecuenciaNumeros sn;
    sn.leerNumero();
    sn.evaluarNumero();
    return 0;
}