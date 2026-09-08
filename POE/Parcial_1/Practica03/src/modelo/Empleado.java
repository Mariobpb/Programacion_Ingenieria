package modelo;

public class Empleado {

    private String nombre;
    private String puesto;
    private double pagoHora;
    private double horasTrabajadasMes;
    private double salarioMensual;

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getPuesto() {
        return puesto;
    }

    public void setPuesto(String puesto) {
        this.puesto = puesto;
    }

    public double getPagoHora() {
        return pagoHora;
    }

    public void setPagoHora(double pagoHora) {
        this.pagoHora = pagoHora;
    }

    public double getHorasTrabajadasMes() {
        return horasTrabajadasMes;
    }

    public void setHorasTrabajadasMes(double horasTrabajadasMes) {
        this.horasTrabajadasMes = horasTrabajadasMes;
    }

    public double getSalarioMensual() {
        return salarioMensual;
    }

    public void setSalarioMensual(double salarioMensual) {
        this.salarioMensual = salarioMensual;
    }

    public double obtenerSalarioMensual() {
        double salario = pagoHora * horasTrabajadasMes;
        if (horasTrabajadasMes >= 100 && horasTrabajadasMes <= 200)
            salario *= 1.1;
        else if (horasTrabajadasMes > 200 && horasTrabajadasMes <= 220)
            salario *= 1.2;
        else if (horasTrabajadasMes > 220 && horasTrabajadasMes <= 230)
            salario *= 1.3;
        return salario *= 0.84;
    }
    
    public String imprimirDatosTrabajador() {
        String text = "";
        text += "Nombre: " +  getNombre();
        text += "  Puesto: " +  getPuesto();
        text += "  Pago/hora: " +  getPagoHora();
        text += "  Horas trabajadas en el mes: " +  getHorasTrabajadasMes();
        text += "  Salario Mensual: " +  getSalarioMensual();
        return text;
    }
}
