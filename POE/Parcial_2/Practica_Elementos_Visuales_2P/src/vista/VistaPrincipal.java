package vista;

import controlador.ControlAdmin;
import controlador.ControlRecepcion;
import modelo.Usuario;

import javax.swing.*;
import java.awt.*;

public class VistaPrincipal extends JFrame implements FormatoVista {
    private VistaLogin vtnLogin = null;
    private PanelGestionEmpleados panelEmpleados = null;
    private PanelGestionCitas panelCitas = null;
    private Usuario usuario = null;

    private ControlAdmin controlAdmin = null;
    private ControlRecepcion controlRecepcion = null;

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

        if (usuario.getRol().contains("ADMIN")) {
            panelEmpleados = new PanelGestionEmpleados(usuario);
            panelEmpleados.mostrarVentana();

            panelContenido = panelEmpleados;
            controlAdmin = new ControlAdmin(this);
        } else if (usuario.getRol().contains("RECEPCION")) {
            panelCitas = new PanelGestionCitas(usuario);
            panelCitas.mostrarVentana();

            panelContenido = panelCitas;
            controlRecepcion = new ControlRecepcion(this);
        }
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
        if (panelContenido != null) {
            panelPrincipal.add(panelContenido, BorderLayout.CENTER);
        }
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