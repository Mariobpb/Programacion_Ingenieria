package modelo;

public class Alumno extends Persona{
    private String carrera;
    private double calMate;
    private double calFisica;
    private double calProgra;
    private double Promedio;

    public Alumno() {
    }

    public Alumno(String nombre, int edad, String email, String codigo, String carrera) {
        super(nombre, edad, email, codigo);
        this.carrera = carrera;
    }

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }

    public double getCalMate() {
        return calMate;
    }

    public void setCalMate(double calMate) {
        this.calMate = calMate;
    }

    public double getCalFisica() {
        return calFisica;
    }

    public void setCalFisica(double calFisica) {
        this.calFisica = calFisica;
    }

    public double getCalProgra() {
        return calProgra;
    }

    public void setCalProgra(double calProgra) {
        this.calProgra = calProgra;
    }

    public double getPromedio() {
        return Promedio;
    }

    public void setPromedio(double promedio) {
        Promedio = promedio;
    }

    public void obtenerPromedio() {
        setPromedio(    ( getCalMate() +
                        getCalFisica() +
                        getCalProgra()) / 3
        );
    }

    @Override
    public String mostrarInfo(){
        String info = super.mostrarInfo();
        info += "Carrera: " + getCarrera() + "\n" +
                "Matemáticas: " + getCalMate() + "\n" +
                "Física: " + getCalFisica() + "\n" +
                "Programación: " + getCalProgra() + "\n" +
                "Promedio: " + getPromedio() + "\n";
        return info;
    }
}
