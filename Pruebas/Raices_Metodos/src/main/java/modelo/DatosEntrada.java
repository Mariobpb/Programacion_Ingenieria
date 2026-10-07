package modelo;

public class DatosEntrada extends Redondeo {
    private Funcion funcion;
    private double x0;
    private double x1;
    private double tolerancia;

    public DatosEntrada(Funcion funcion, double x0, double tolerancia) {
        this.funcion = funcion;
        this.x0 = x0;
        this.tolerancia = tolerancia;
    }

    public DatosEntrada(Funcion funcion, double x0, double x1, double tolerancia) {
        this.funcion = funcion;
        this.x0 = x0;
        this.x1 = x1;
        this.tolerancia = tolerancia;
    }

    public Funcion getFuncion() {
        return funcion;
    }

    public void setFuncion(Funcion funcion) {
        this.funcion = funcion;
    }

    public double getTolerancia() {
        return tolerancia;
    }

    public void setTolerancia(double tolerancia) {
        this.tolerancia = tolerancia;
    }

    public double getX1() {
        return x1;
    }

    public void setX1(double x1) {
        this.x1 = x1;
    }

    public double getX0() {
        return x0;
    }

    public void setX0(double x0) {
        this.x0 = x0;
    }
}
