package modelo;

public class Administrador extends Usuario {
    public Administrador(String nombre, int edad, String urlFoto, String domicilio, String rol, String contrasena, String usuario) {
        super(nombre, edad, urlFoto, domicilio, rol, contrasena, usuario);
    }

    public void agregarDoctor(Doctor doctor){

    }

    public void agregarUsuario(Usuario usuario){

    }

    public void modificarDoctor(Doctor doctor){

    }

    public void modificarUsuario(Usuario usuario){

    }

    public void eliminarDoctor(Doctor doctor){

    }

    public void eliminarUsuario(Usuario usuario){

    }

    @Override
    public void mostrarInfo(){
        
    }
}
