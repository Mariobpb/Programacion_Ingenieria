#include <iostream>
using namespace std;

class NumeroParImpar {
    // Atributo de la clase
    private:
        int numero;

    // Métodos de la clase
    public:
        int getNumero();
        void setNumero(int numero);
        void leerNumero();
        void evaluarNumero();
};

int NumeroParImpar::getNumero(){
    return this->numero;
}

void NumeroParImpar::setNumero(int numero){
    this->numero = numero;
}

void NumeroParImpar::leerNumero(){
    int num;
    cout << "Ingresa un numero entero:  ";
    cin >> num;
    setNumero(num);
}

void NumeroParImpar::evaluarNumero(){
    cout << "El numero " << getNumero(); 
    if(getNumero() % 2 == 0){
        cout << " es par" << endl;
    }else{
        cout << " es impar" << endl;
    }
}

int main (){
    NumeroParImpar obj;
    obj.leerNumero();
    obj.evaluarNumero();

    return 0;
}