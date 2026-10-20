package modelo;

public class Usuario extends Empleado {
    private String usuario;
    private String contrasena;
    private String rol;

    public Usuario(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String turno, String usuario, String contrasena, String rol) {
        super(nombre, edad, telefono, urlFoto, domicilio, salarioBase, turno);
        this.usuario = usuario;
        this.contrasena = contrasena;
        this.rol = rol;
    }

    public Usuario(String nombre, int edad, long telefono, String domicilio, double salarioBase, String turno, String usuario, String contrasena, String rol) {
        super(nombre, edad, telefono, domicilio, salarioBase, turno);
        this.usuario = usuario;
        this.contrasena = contrasena;
        this.rol = rol;
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