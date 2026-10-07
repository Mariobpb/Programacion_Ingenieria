package modelo.metodos;

import modelo.DatosEntrada;
import modelo.Redondeo;

public class BirgeVieta extends Redondeo {
    DatosEntrada datosEntrada = null;

    public BirgeVieta(DatosEntrada datosEntrada) {
        this.datosEntrada = datosEntrada;
    }

    public void encontrarRaices(){
        int i = 1;
        double x0 = datosEntrada.getX0();
        double x1 = 0;

        System.out.println("i\t\txk\t\txk+1\t\t| xk+1 - xk | < " + datosEntrada.getTolerancia());
        do{
            x1 = redondear(x0 - (datosEntrada.getFuncion().evaluar(x0)/datosEntrada.getFuncion().evaluarDerivada(x0)));
            System.out.println(i+"\t\t"+ x0 +"\t\t" + x1 + "\t\t" + calcularDiferenciasX(x1, x0));
            x0 = x1;
            i++;
        }while (calcularDiferenciasX(x1, x0) > datosEntrada.getTolerancia());
        System.out.println("\nDiferencia = " + calcularDiferenciasX(x1, x0));
        System.out.println("x = " + x1);
    }

    public double calcularDiferenciasX(double x1, double x0){
        return redondear(Math.abs(x1- x0));
    }
}
