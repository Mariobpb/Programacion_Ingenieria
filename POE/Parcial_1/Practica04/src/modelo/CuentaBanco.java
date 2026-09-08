package modelo;

public class CuentaBanco {
    private String nombreC;
    private String numeroC;
    private double saldoC;

    public CuentaBanco() {
        this.nombreC = "";
        this.numeroC = "";
        this.saldoC = 0;
    }

    public String getNombreC() {
        return nombreC;
    }

    public void setNombreC(String nombreC) {
        this.nombreC = nombreC;
    }

    public String getNumeroC() {
        return numeroC;
    }

    public void setNumeroC(String numeroC) {
        this.numeroC = numeroC;
    }

    public double getSaldoC() {
        return saldoC;
    }

    public void setSaldoC(double saldoC) {
        this.saldoC = saldoC;
    }

    public String imprimirDatos(){
        String text = "";
        text += "Nombre: " + getNombreC();
        text += "\nNumero de cuenta: " + getNumeroC();
        text += "\nSaldo: " + getSaldoC() + "$";
        return text;
    }

    public void abonarCuenta(double cantidad){
        setSaldoC(getSaldoC() +  cantidad);
    }
    public boolean retirarCuenta(double cantidad){
        if(cantidad<=getSaldoC()){
            setSaldoC(getSaldoC() -  cantidad);
            return true;
        }
        return false;
    }
}
