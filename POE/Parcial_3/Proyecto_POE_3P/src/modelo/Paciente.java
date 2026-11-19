package modelo;

public class Paciente extends Persona {
    private String restricciones;

    public Paciente(String nombre, int edad, long telefono, String restricciones) {
        super(nombre, edad, telefono);
        this.restricciones = restricciones;
    }
    public Paciente(String nombre, int edad, String restricciones) {
        super(nombre, edad);
        this.restricciones = restricciones;
    }
    public Paciente(String nombre, int edad, int telefono) {
        super(nombre, edad, telefono);
    }
    public Paciente(String nombre, int edad) {
        super(nombre, edad);
    }

    public String getRestricciones() {
        return restricciones;
    }

    public void setRestricciones(String restricciones) {
        this.restricciones = restricciones;
    }
}
