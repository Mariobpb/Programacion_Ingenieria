package modelo;

import vista.VentanaFigura;

public class Figura {

    private double largo;
    private double ancho;
    private double alto;
    private double volumen;

    public Figura() {

    }

    public Figura(double largo, double ancho, double alto) {
        
        if (largo < 0) largo *= -1;
        if (ancho < 0) ancho *= -1;
        if (alto < 0) alto *= -1;
        
        this.largo = largo;
        this.ancho = ancho;
        this.alto = alto;
    }

    public double getLargo() {
        return largo;
    }

    public void setLargo(double largo) {
        this.largo = largo;
    }

    public double getAncho() {
        return ancho;
    }

    public void setAncho(double ancho) {
        this.ancho = ancho;
    }

    public double getAlto() {
        return alto;
    }

    public void setAlto(double alto) {
        this.alto = alto;
    }

    public double getVolumen() {
        return volumen;
    }

    public void setVolumen(double volumen) {
        this.volumen = volumen;
    }

    public double obtenerVolumen(){
        return getLargo( ) * getAncho( ) * getAlto( );
    }
}
