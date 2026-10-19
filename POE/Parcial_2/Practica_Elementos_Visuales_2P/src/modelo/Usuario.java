package modelo;

public class Usuario extends Empleado {
    private String usuario;
    private String contrasena;
    private String rol;

    public Usuario(String nombre, int edad, String urlFoto, String domicilio, String rol, String contrasena, String usuario) {
        super(nombre, edad, urlFoto, domicilio);
        this.rol = rol;
        this.contrasena = contrasena;
        this.usuario = usuario;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    public String getContrasena() {
        return contrasena;
    }

    public void setContrasena(String contrasena) {
        this.contrasena = contrasena;
    }

    public String getRol() {
        return rol;
    }

    public void setRol(String rol) {
        this.rol = rol;
    }
}
