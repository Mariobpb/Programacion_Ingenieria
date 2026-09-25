package modelo;

public class Modelo {
    private int precioTotal;

    public int getPrecio() {
        return precioTotal;
    }

    public void setPrecio(int precioTotal) {
        this.precioTotal = precioTotal;
    }

    public int calcularPrecio(String ing, String turno, String pago) {
        int precio = 0;

        switch (ing) {
            case "IDS":
                precio += 500;
                break;
            case "IDESI":
                precio += 400;
                break;
            case "MECATRONICA":
                precio += 300;
                break;
            case "INDUSTRIAL":
                precio += 200;
                break;
        }

        switch (turno) {
            case "MATUTINO":
                precio += 500;
                break;
            case "VESPERTINO":
                precio += 300;
                break;
        }

        switch (pago) {
            case "EFECTIVO":
                precio += 1000;
                break;
            case "DEBITO":
                precio += 1300;
                break;
            case "CREDITO":
                precio += 1500;
                break;
        }

        return precio;
    }
}
