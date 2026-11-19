package modelo;

public class Recepcionista extends Usuario {
    public Recepcionista(String nombre, int edad, long telefono, String urlFoto, String domicilio, double salarioBase, String turno, String usuario, String contrasena) {
        super(nombre, edad, telefono, urlFoto, domicilio, salarioBase, turno, usuario, contrasena, "RECEPCIONISTA");
    }

    public Recepcionista(String nombre, int edad, long telefono, String domicilio, double salarioBase, String turno, String usuario, String contrasena) {
        super(nombre, edad, telefono, domicilio, salarioBase, turno, usuario, contrasena, "RECEPCIONISTA");
    }

    public void agendarCita(Cita cita) {

    }
    public void cancelarCita(Cita cita) {

    }
    public void modificarCita(Cita cita) {

    }

    public void registrarPaciente(Paciente paciente) {

    }
    public void modificarPaciente(Paciente paciente) {

    }
}