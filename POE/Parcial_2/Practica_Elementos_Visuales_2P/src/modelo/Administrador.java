package modelo;

public class Administrador extends Usuario {
    public Administrador(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String usuario, String contrasena) {
        super(nombre, edad, telefono, urlFoto, domicilio, salarioBase, usuario, contrasena, "ADMINISTRADOR");
    }

    public void agregarDoctor(Doctor doctor) {

    }
    public void modificarDoctor(Doctor doctor) {

    }
    public void eliminarDoctor(Doctor doctor) {

    }

    public void agregarRecepcionista(Recepcionista recepcionista) {

    }
    public void modificarRecepcionista(Recepcionista recepcionista) {

    }
    public void eliminarRecepcionista(Recepcionista recepcionista) {

    }

    public void agregarAdministrador(Administrador administrador) {

    }
    public void modificarAdministrador(Administrador administrador) {

    }
    public void eliminarAdministrador(Administrador administrador) {

    }
}
