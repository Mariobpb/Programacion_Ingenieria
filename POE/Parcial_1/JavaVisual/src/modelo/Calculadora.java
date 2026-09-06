package modelo;

public class Calculadora {

    private double num1;
    private double num2;
    private double res;

    public double getNum1() {
        return num1;
    }

    public void setNum1(double num1) {
        this.num1 = num1;
    }

    public double getNum2() {
        return num2;
    }

    public void setNum2(double num2) {
        this.num2 = num2;
    }

    public double getRes() {
        return res;
    }

    public void setRes(double res) {
        this.res = res;
    }

    public void sumarNumeros() {
        setRes(getNum1() + getNum2());

    }
    
    public void restarNumeros() {
        setRes(getNum1() - getNum2());

    }
    
    public void multiplicarNumeros() {
        setRes(getNum1() * getNum2());

    }
    
    public void dividirNumeros() {
        setRes(getNum1() / getNum2());

    }
}
