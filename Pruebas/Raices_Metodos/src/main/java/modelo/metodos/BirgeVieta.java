package modelo.metodos;

import modelo.DatosEntrada;
import modelo.MetodoNumerico;
import modelo.Redondeo;

public class BirgeVieta extends Redondeo implements MetodoNumerico {
    private double x2;
    DatosEntrada datosEntrada = null;

    public BirgeVieta(DatosEntrada datosEntrada) {
        this.datosEntrada = datosEntrada;
    }

    public double getX2() {
        return x2;
    }

    @Override
    public void calcularRaiz() {
        int i = 1;
        double x0 = datosEntrada.getX0();
        double x1 = datosEntrada.getX1();

        System.out.println("i\t\ta\t\tb\t\txr\t\t| f(xr) < " + datosEntrada.getTolerancia());
        do{
            x2 = redondear(x1 - ((datosEntrada.getFuncion().evaluar(x1))*(x1-x0))/
                    (redondear(datosEntrada.getFuncion().evaluar(x1))-redondear(datosEntrada.getFuncion().evaluar(x0))) );
            System.out.println(i+"\t\t"+ x0 +"\t\t" + x1 + "\t\t" + x2 +  "\t\t" + calcularTolerancia());
            x0 = x1;
            x1 = x2;
            i++;
            if (i > 100) break;
        }while (calcularTolerancia() > datosEntrada.getTolerancia());
        System.out.println("\nf(xr) = " + calcularTolerancia());
        System.out.println("x = " + x1);
    }

    @Override
    public double calcularTolerancia() {
        return Math.abs(redondear(datosEntrada.getFuncion().evaluar(x2)));
    }

    @Override
    public double validarCondicion() {
        return
    }


}
