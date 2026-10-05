package com.metodos.modelo.metodos;

import com.metodos.modelo.DatosEntrada;
import com.metodos.modelo.Redondeo;

public class Secante extends Redondeo {
    private DatosEntrada datosEntrada;
    private double x2;

    public Secante(DatosEntrada datosEntrada) {
        this.datosEntrada = datosEntrada;
        this.x2 = 0;
    }

    public void encontrarRaices(){
        int i = 1;
        double x0 = datosEntrada.getX0();
        double x1 = datosEntrada.getX1();

        System.out.println("i\t\txn-1\t\txn\t\txn+1\t\t| xn+1 - xn | < " + datosEntrada.getTolerancia());
        while (calcularDiferenciasX(x1, x0) > datosEntrada.getTolerancia()){
            x2 = redondear(x1 - (datosEntrada.getFuncion().evaluar(x1)*((x1- x0)/(datosEntrada.getFuncion().evaluar(x1) - datosEntrada.getFuncion().evaluar(x0)))));
            System.out.println(i+"\t\t"+ x0 +"\t\t" + x1 + "\t\t"+ x2 +"\t\t" + calcularDiferenciasX(x2, x1));
            x0 = x1;
            x1 = x2;
            i++;
        }
        System.out.println("\nDiferencia = " + calcularDiferenciasX(x1, x0));
        System.out.println("x = " + x1);
    }

    public double calcularDiferenciasX(double x2, double x1){
        return redondear(Math.abs(x2- x1));
    }

    public double getX2() {
        return x2;
    }

    public void setX2(double x2) {
        this.x2 = x2;
    }
}
