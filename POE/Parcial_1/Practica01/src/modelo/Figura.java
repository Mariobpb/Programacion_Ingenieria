package modelo;

public class Figura {

    private double largo;
    private double ancho;
    private double alto;
    private double volumen;

    public Figura() {
        this.largo = 1;
        this.ancho = 1;
        this.alto = 1;
    }

    public Figura(double largo, double ancho, double alto) {
        this.largo = (largo < 0) ? 1: largo;
        this.ancho = (ancho < 0) ? 1: ancho;
        this.alto = (alto < 0) ? 1: alto;
    }

    public double getLargo() {
        return largo;
    }

    public void setLargo(double largo) {
        this.largo = (largo < 0) ? 1: largo;
    }

    public double getAncho() {
        return ancho;
    }

    public void setAncho(double ancho) {
        this.ancho = (ancho < 0) ? 1: ancho;
    }

    public double getAlto() {
        return alto;
    }

    public void setAlto(double alto) {
        this.alto = (alto < 0) ? 1: alto;
    }

    public double getVolumen() {
        return volumen;
    }

    public void setVolumen(double volumen) {
        this.volumen = volumen;
    }

    public double obtenerVolumen(){ return getLargo( ) * getAncho( ) * getAlto( ); }
}
