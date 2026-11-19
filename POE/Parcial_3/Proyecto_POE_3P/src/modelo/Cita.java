package modelo;

import java.util.Date;

public class Cita {
    private Doctor doctor;
    private Paciente paciente;
    private Date fecha;
    private String tipoCita;
    private String sintomas;
    private boolean requiereFactura;
    private int costo;

    public Cita(Doctor doctor, Paciente paciente, Date fecha, String tipoCita) {
        this.doctor = doctor;
        this.paciente = paciente;
        this.fecha = fecha;
        this.tipoCita = tipoCita;
        sintomas = "Sin especificar";
        requiereFactura = false;
        costo = -1;
    }

    public Doctor getDoctor() {
        return doctor;
    }

    public void setDoctor(Doctor doctor) {
        this.doctor = doctor;
    }

    public Paciente getPaciente() {
        return paciente;
    }

    public void setPaciente(Paciente paciente) {
        this.paciente = paciente;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public String getTipoCita() {
        return tipoCita;
    }

    public void setTipoCita(String tipoCita) {
        this.tipoCita = tipoCita;
    }

    public String getSintomas() {
        return sintomas;
    }

    public void setSintomas(String sintomas) {
        this.sintomas = sintomas;
    }

    public boolean isRequiereFactura() {
        return requiereFactura;
    }

    public void setRequiereFactura(boolean requiereFactura) {
        this.requiereFactura = requiereFactura;
    }

    public int getCosto() {
        return costo;
    }

    public void setCosto(int costo) {
        this.costo = costo;
    }
}
