package modelo;

public class Doctor extends Empleado {
    private boolean titulo;
    private String especialidad;

    public Doctor(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String turno, boolean titulo, String especialidad) {
        super(nombre, edad, telefono, urlFoto, domicilio, salarioBase, turno);
        this.titulo = titulo;
        this.especialidad = especialidad;
    }

    public Doctor(String nombre, int edad, long telefono, String domicilio, double salarioBase, String turno, boolean titulo, String especialidad) {
        super(nombre, edad, telefono, domicilio, salarioBase, turno);
        this.titulo = titulo;
        this.especialidad = especialidad;
    }

    public boolean isTitulo() {
        return titulo;
    }

    public void setTitulo(boolean titulo) {
        this.titulo = titulo;
    }

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }
}