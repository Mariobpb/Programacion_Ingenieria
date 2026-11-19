package modelo;

public class Empleado extends Persona {
    private String urlFoto;
    private String domicilio;
    private double salarioBase;
    private String turno;

    public Empleado(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String turno) {
        super(nombre, edad, telefono);
        this.urlFoto = urlFoto;
        this.domicilio = domicilio;
        this.salarioBase = salarioBase;
        this.turno = turno;
    }

    public Empleado(String nombre, int edad, long telefono, String domicilio, double salarioBase, String turno) {
        super(nombre, edad, telefono);
        this.urlFoto = "/imagenes/default_foto.png";
        this.domicilio = domicilio;
        this.salarioBase = salarioBase;
        this.turno = turno;
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

    public String getTurno() {
        return turno;
    }

    public void setTurno(String turno) {
        this.turno = turno;
    }
}