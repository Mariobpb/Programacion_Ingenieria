package modelo;

public class Empleado extends Persona{
    private String urlFoto;
    private String domicilio;

    public Empleado(String nombre, int edad, String urlFoto, String domicilio) {
        super(nombre, edad);
        this.urlFoto = urlFoto;
        this.domicilio = domicilio;
    }
}
