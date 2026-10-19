package modelo;

public class Recepcionista extends Usuario{
    public Recepcionista(String nombre, int edad, String urlFoto, String domicilio, String rol, String contrasena, String usuario) {
        super(nombre, edad, urlFoto, domicilio, rol, contrasena, usuario);
    }

    public void agendarCita(Cita cita){

    }
}
