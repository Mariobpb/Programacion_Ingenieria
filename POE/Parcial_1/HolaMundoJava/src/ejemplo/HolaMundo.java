package ejemplo;

public class HolaMundo {
    // Definir atributos
    private int numero = 20;
    private String texto = "Hoy aprendí Java";

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }
    
    
    
    
    // Definir método
    public void imprimirSaludo(){
        System.out.println("Hola Mundo de Java");
    }
    
    public void imprimirDatos(){
        System.out.println("Numero = " + numero);
        System.out.println("Texto = " + texto);
    }
}
