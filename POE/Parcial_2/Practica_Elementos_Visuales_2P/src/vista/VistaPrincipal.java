package vista;

import controlador.ControlLogin;

import javax.swing.*;

public class VentanaPrincipal extends JFrame implements FormatoVentana{
    private VentanaLogin vtnLogin = null;
    private ControlLogin controlLogin = null;

    private JPanel panelPrincipal = null;

    public VentanaPrincipal(VentanaLogin vtnLogin) {
        this.vtnLogin = vtnLogin;
        setTitle("Gestor de Citas");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1300, 900);
        setLocationRelativeTo(null);
        setResizable(false);
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
}
