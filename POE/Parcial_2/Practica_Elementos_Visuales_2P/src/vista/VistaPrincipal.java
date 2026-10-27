package vista;

import modelo.Usuario;

import javax.swing.*;
import java.awt.*;

public class VistaPrincipal extends JFrame implements FormatoVista {
    private VistaLogin vtnLogin = null;
    private PanelGestionEmpleados panelEmpleados = null;
    private PanelGestionCitas panelCitas = null;
    private Usuario usuario = null;

    private JPanel panelPrincipal = null;
    private JPanel panelContenido = null;

    public VistaPrincipal(VistaLogin vtnLogin, Usuario usuario) {
        this.vtnLogin = vtnLogin;
        this.usuario = usuario;

        setTitle("Gestor de Citas Médicas - " + usuario.getNombre());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1300, 900);
        setLocationRelativeTo(null);
        setResizable(false);
    }

    @Override
    public void mostrarVentana() {
        instanciarComponentes();
        definirLayout();
        configurarComponenetes();
        agregarComponentes();

        add(panelPrincipal);
        setVisible(true);
    }

    @Override
    public void instanciarComponentes() {
        panelPrincipal = new JPanel();
    }

    @Override
    public void cargarImagenes() { }

    @Override
    public void definirLayout() {
        panelPrincipal.setLayout(new BorderLayout());
    }

    @Override
    public void configurarComponenetes() { }

    @Override
    public void configurarImagenes() { }

    @Override
    public void agregarComponentes() {
        panelPrincipal.add(panelContenido, BorderLayout.CENTER);
    }

    public void setPanelEmpleados(PanelGestionEmpleados panelEmpleados) {
        this.panelEmpleados = panelEmpleados;
        this.panelContenido = panelEmpleados;
    }

    public void setPanelCitas(PanelGestionCitas panelCitas) {
        this.panelCitas = panelCitas;
        this.panelContenido = panelCitas;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public JPanel getPanelContenido() {
        return panelContenido;
    }

    public PanelGestionEmpleados getPanelEmpleados() {
        return panelEmpleados;
    }

    public PanelGestionCitas getPanelCitas() {
        return panelCitas;
    }

    public VistaLogin getVtnLogin() {
        return vtnLogin;
    }
}