package modelo;

public class Doctor extends Empleado{
    private String titulo;

    public Doctor(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String titulo) {
        super(nombre, edad, telefono, urlFoto, domicilio, salarioBase);
        this.titulo = titulo;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
}
