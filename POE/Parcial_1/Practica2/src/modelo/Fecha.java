package modelo;

public class Fecha {
    private int dia;
    private int mes;
    private int anio;

    public Fecha() {
        this.dia = 1;
        this.mes = 1;
        this.anio = 1;
    }

    public Fecha(int dia, int anio, int mes) {
        this.dia = dia;
        this.mes = mes;
        this.anio = anio;

        if (validarFecha() == 0) {
            this.dia = 1;
            this.mes = 1;
            this.anio = 1;
        }
    }

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getAnio() {
        return anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }

    public int validarFecha(){
        int diaLimite;
        if (anio < 1 || mes < 1 || mes > 12 || dia < 1)
            return 0;
        switch (mes) {
            case 2:
                diaLimite = ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11:
                diaLimite = 30;
                break;
            default:
                diaLimite = 31;
                break;
        }
        return (dia > diaLimite) ? 0 : 1;
    }

    public String imprimirFechaCorta() {
        return dia + "/" + mes + "/" + anio;
    }

    public String imprimirFechaLarga() {
        String mesTexto = "";
        switch (mes){
            case 1:
                mesTexto = "Enero";
                break;
            case 2:
                mesTexto = "Febrero";
                break;
            case 3:
                mesTexto = "Marzo";
                break;
            case 4:
                mesTexto = "Abril";
                break;
            case 5:
                mesTexto = "Mayo";
                break;
            case 6:
                mesTexto = "Junio";
                break;
            case 7:
                mesTexto = "Julio";
                break;
            case 8:
                mesTexto = "Agosto";
                break;
            case 9:
                mesTexto = "Septiembre";
                break;
            case 10:
                mesTexto = "Octubre";
                break;
            case 11:
                mesTexto = "Noviembre";
                break;
            case 12:
                mesTexto = "Diciembre";
                break;
        }
        return dia + " de " + mesTexto + " de " + anio;
    }
}
