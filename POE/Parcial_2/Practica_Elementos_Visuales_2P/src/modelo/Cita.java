package modelo;

import java.util.Date;

public class Cita {
    private Doctor doctor;
    private Empleado empleado;
    private Date fecha;
    private String tipoCita;
    private int costo;

    public Cita(Doctor doctor, Empleado empleado, Date fecha) {
        this.doctor = doctor;
        this.empleado = empleado;
        this.fecha = fecha;
    }


}
