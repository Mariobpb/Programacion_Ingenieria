package modelo;

public class Doctor extends Empleado{
    public Doctor(String nombre, int edad, int telefono, String urlFoto, String domicilio) {
        super(nombre, edad, telefono, urlFoto, domicilio);
    }

    public Doctor(String nombre, int edad, String urlFoto, String domicilio) {
        super(nombre, edad, urlFoto, domicilio);
    }
}
