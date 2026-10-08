package modelo.metodos;

import modelo.DatosEntrada;
import modelo.Redondeo;

public class ReglaFalsa extends Redondeo {
    private double x2;
    DatosEntrada datosEntrada = null;

    public ReglaFalsa(DatosEntrada datosEntrada) {
        this.datosEntrada = datosEntrada;
    }

    public void encontrarRaices(){
        int i = 1;
        double x0 = datosEntrada.getX0();
        double x1 = datosEntrada.getX1();

        System.out.println("i\t\ta\t\tb\t\txr\t\t|a-b|\t\t|f(xr)| < " + datosEntrada.getTolerancia());
        do{
            //System.out.println("\nf(" + x0 + ") = " + redondear(datosEntrada.getFuncion().evaluar(x0)));
            //System.out.println("\nf(" + x1 + ") = " + redondear(datosEntrada.getFuncion().evaluar(x1)));
            x2 = redondear(x1 - (redondear(datosEntrada.getFuncion().evaluar(x1))*(x1-x0))/
                    (redondear(datosEntrada.getFuncion().evaluar(x1))-redondear(datosEntrada.getFuncion().evaluar(x0))));
            System.out.println(i+"\t\t"+ x0 +"\t\t" + x1 + "\t\t" + x2 +  "\t\t" + redondear(x1-x0) + "\t\t" + calcularTolerancia());
            if (redondear(datosEntrada.getFuncion().evaluar(x2)) < 0) {
                x0 = x2;
            } else {
                x1 = x2;
            }
            i++;
            if (i > 100) break;
        }while (calcularTolerancia() > datosEntrada.getTolerancia());
        System.out.println("\n|f(xr)| = " + calcularTolerancia());
        System.out.println("x = " + x2);
    }

    private double calcularTolerancia() {
        return Math.abs(redondear(datosEntrada.getFuncion().evaluar(x2)));
    }

    public double getX2() {
        return x2;
    }
}
