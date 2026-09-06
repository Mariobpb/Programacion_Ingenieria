package ejemplo;

public class MainHolaMundo {
    public static void main(String[] args){
        // Se crea el objeto
        HolaMundo objeto = new HolaMundo();
        
        objeto.setNumero(100);
        objeto.setTexto("NetBeans es un IDE para JAVA");
        objeto.imprimirSaludo();
        objeto.imprimirDatos();
    }
    
}
