package vista;

import controlador.ControlLogin;

import javax.swing.*;

public class VistaPrincipal extends JFrame implements FormatoVista {
    private VistaLogin vtnLogin = null;
    private ControlLogin controlLogin = null;

    private JPanel panelPrincipal = null;

    public VistaPrincipal(VistaLogin vtnLogin) {
        this.vtnLogin = vtnLogin;
        setTitle("Gestor de Citas Medicas");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1300, 900);
        setLocationRelativeTo(null);
        setResizable(false);
    }

    @Override
    public void mostrarVentana() {
        instanciarComponentes();


    }

    @Override
    public void instanciarComponentes() {

    }

    @Override
    public void definirLayout() {

    }

    @Override
    public void configurarListeners() {

    }

    @Override
    public void cargarImagenes() {

    }

    @Override
    public void configurarComponenetes() {

    }

    @Override
    public void configurarImagenes() {

    }

    @Override
    public void agregarComponentes() {

    }
}
