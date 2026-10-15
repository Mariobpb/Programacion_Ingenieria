package modelo;

public class Docente extends Persona{
    private int cantHoras;
    private double pahoHora;
    private double salario;

    public int getCantHoras() {
        return cantHoras;
    }

    public void setCantHoras(int cantHoras) {
        this.cantHoras = cantHoras;
    }

    public double getPahoHora() {
        return pahoHora;
    }

    public void setPahoHora(double pahoHora) {
        this.pahoHora = pahoHora;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void calcularSalario(){
        setSalario(getCantHoras() * getPahoHora());
    }

    public void evaluarAlumno(Alumno objAl, double calMate,
                                            double calFisica,
                                            double calProgra) {
        objAl.setCalMate(calMate);
        objAl.setCalFisica(calFisica);
        objAl.setCalProgra(calProgra);
        objAl.obtenerPromedio();
    }

    @Override
    public String mostrarInfo(){
        String info = super.mostrarInfo();
        info += "Horas impartidas: " + getCantHoras() + "\n" +
                "Pago x Hora: " + getPahoHora() + "\n" +
                "Salario: " + getSalario() + "\n";
        return info;
    }
}
