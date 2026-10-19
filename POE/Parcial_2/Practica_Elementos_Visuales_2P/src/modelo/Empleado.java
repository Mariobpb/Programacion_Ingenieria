package modelo;

public class Empleado extends Persona{
    private String urlFoto;
    private String domicilio;
    private double salarioBase;

    public Empleado(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase) {
        super(nombre, edad, telefono);
        this.urlFoto = urlFoto;
        this.domicilio = domicilio;
        this.salarioBase = salarioBase;
    }

    public String getUrlFoto() {
        return urlFoto;
    }

    public void setUrlFoto(String urlFoto) {
        this.urlFoto = urlFoto;
    }

    public String getDomicilio() {
        return domicilio;
    }

    public void setDomicilio(String domicilio) {
        this.domicilio = domicilio;
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }
}
