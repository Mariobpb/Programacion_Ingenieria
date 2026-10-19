package vista;

import controlador.ControlLogin;

import javax.swing.*;

public class VentanaPrincipal implements FormatoVentana{
    private VentanaLogin vtnLogin = null;
    private ControlLogin controlLogin = null;

    private JFrame vtnPrincipal = null;
    private JPanel panelPrincipal = null;

    public VentanaPrincipal(VentanaLogin vtnLogin) {
        this.vtnLogin = vtnLogin;
        vtnPrincipal = new JFrame("Gestor de Citas");
        vtnPrincipal.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtnPrincipal.setSize(1300, 900);
        vtnPrincipal.setLocationRelativeTo(null);
        vtnPrincipal.setResizable(false);
    }

    @Override
    public void mostrarVentana() {

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
    public void configurarComponenetes() {

    }

    @Override
    public void agregarComponentes() {

    }

    public JFrame getVtnPrincipal() {
        return vtnPrincipal;
    }
}
