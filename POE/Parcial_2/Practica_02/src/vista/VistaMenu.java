package vista;

import controlador.ControladorMenu;

import javax.swing.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.Objects;

public class VistaMenu {
    private ControladorMenu control;

    private JFrame vtn = null;
    private JMenuBar mnBarra = null;

    // Barra
    private JMenu mnArchivo = null;
    private JMenu mnEdicion = null;
    private JMenu mnHerramientas = null;

    // Menu -> Archivo
    private JMenuItem mnAbrir = null;
    private JMenu mnExportar = null;
    private JMenuItem mnSalir = null;

    // Menu -> Edicion
    private JMenuItem mnCopiar = null;
    private JMenuItem mnCortar = null;
    private JMenuItem mnPegar = null;

    // Menu -> Herramientas
    private JMenu mnAjustes = null;
    private JMenuItem mnConfiguracion = null;
    private JMenu mnOpciones = null;

    // Sub-menu -> Exportar -> Archivo
    private JMenuItem mnPDF = null;
    private JMenuItem mnDOC = null;

    // Sub-menu -> Ajustes -> Herramientas
    private JMenuItem mnOscuro = null;
    private JMenuItem mnClaro = null;

    // Sub-menu -> Opciones -> Herramientas
    private JMenuItem mnActualizar = null;
    private JMenuItem mnRestaurar = null;
    private JMenuItem mnModificar = null;

    // Imagenes
    private ImageIcon imgAbrir = null;
    private ImageIcon imgPDF = null;
    private ImageIcon imgDOC = null;
    private ImageIcon imgSalir = null;
    private ImageIcon imgCopiar = null;
    private ImageIcon imgCortar = null;
    private ImageIcon imgPegar = null;
    private ImageIcon imgOscuro = null;
    private ImageIcon imgClaro = null;
    private ImageIcon imgConfiguracion = null;
    private ImageIcon imgActualizar = null;
    private ImageIcon imgRestaurar = null;
    private ImageIcon imgModificar = null;

    public VistaMenu() {
        vtn = new JFrame("Ejemplo de Menu de Java");
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn.setSize(500, 300);
        vtn.setResizable(false);
    }


    public void dibujarVentana() {
        instanciarMenu();
        cargarImagenes();
        configurarImagenes();
        configurarAtajos();
        configurarMenu();

        control = new ControladorMenu(this);
        vtn.setVisible(true);
    }

    private void instanciarMenu() {
        mnBarra = new JMenuBar();

        // Barra
        mnArchivo = new JMenu("Archivo");
        mnEdicion = new JMenu("Edicion");
        mnHerramientas = new JMenu("Herramientas");

        // Menu -> Archivo
        mnAbrir = new JMenuItem("Abrir");
        mnExportar = new JMenu("Exportar");
        mnSalir = new JMenuItem("Salir");

        // Menu -> Edicion
        mnCopiar = new JMenuItem("Copiar");
        mnCortar = new JMenuItem("Cortar");
        mnPegar = new JMenuItem("Pegar");

        // Menu -> Herramientas
        mnAjustes = new JMenu("Ajustes");
        mnConfiguracion = new JMenuItem("Configuracion");
        mnOpciones = new JMenu("Opciones");

        // Sub-menu -> Exportar -> Archivo
        mnPDF = new JMenuItem("PDF");
        mnDOC = new JMenuItem("DOC");

        // Sub-menu -> Ajustes -> Herramientas
        mnOscuro = new JMenuItem("Modo Oscuro");
        mnClaro = new JMenuItem("Modo Claro");

        // Sub-menu -> Opciones -> Herramientas
        mnActualizar = new JMenuItem("Actualizar");
        mnRestaurar = new JMenuItem("Restaurar");
        mnModificar = new JMenuItem("Modificar");
    }

    public void cargarImagenes() {
        imgAbrir = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnAbrir.png")));
        imgActualizar =  new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/actualizar.png")));
        imgConfiguracion = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/configuracion.png")));
        imgDOC = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnDoc.png")));
        imgPDF = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnPdf.png")));
        imgSalir  = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnSalir.png")));
        imgModificar = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/modificar.png")));
        imgRestaurar  = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/restore.png")));
    }

    private void configurarImagenes () {
        mnAbrir.setIcon(imgAbrir);
        mnPDF.setIcon(imgPDF);
        mnDOC.setIcon(imgDOC);
        mnSalir.setIcon(imgSalir);
        mnConfiguracion.setIcon(imgConfiguracion);
        mnActualizar.setIcon(imgActualizar);
        mnRestaurar.setIcon(imgRestaurar);
        mnModificar.setIcon(imgModificar);
    }

    private void configurarAtajos() {
        mnActualizar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_P, InputEvent.CTRL_DOWN_MASK));
        mnRestaurar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, InputEvent.CTRL_DOWN_MASK));
        mnModificar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_I, InputEvent.CTRL_DOWN_MASK));
        mnConfiguracion.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_U, InputEvent.CTRL_DOWN_MASK));
    }

    private void configurarMenu() {
        // Sub-menu
        mnExportar.add(mnPDF);
        mnExportar.add(mnDOC);

        mnAjustes.add(mnOscuro);
        mnAjustes.add(mnClaro);

        mnOpciones.add(mnActualizar);
        mnOpciones.add(mnRestaurar);
        mnOpciones.add(mnModificar);

        // Menu
        mnArchivo.add(mnAbrir);
        mnArchivo.add(mnExportar);
        mnArchivo.add(mnSalir);

        mnEdicion.add(mnCopiar);
        mnEdicion.add(mnCortar);
        mnEdicion.add(mnPegar);

        mnHerramientas.add(mnAjustes);
        mnHerramientas.add(mnConfiguracion);
        mnHerramientas.add(mnOpciones);

        // Barra
        mnBarra.add(mnArchivo);
        mnBarra.add(mnEdicion);
        mnBarra.add(mnHerramientas);

        // Ventana
        vtn.setJMenuBar(mnBarra);
    }

    public JMenuItem getMnAbrir() {
        return mnAbrir;
    }

    public JMenuItem getMnSalir() {
        return mnSalir;
    }

    public JMenuItem getMnPDF() {
        return mnPDF;
    }

    public JMenuItem getMnDOC() {
        return mnDOC;
    }

    public JMenuItem getMnCopiar() {
        return mnCopiar;
    }

    public JMenuItem getMnCortar() {
        return mnCortar;
    }

    public JMenuItem getMnPegar() {
        return mnPegar;
    }

    public JMenuItem getMnConfiguracion() {
        return mnConfiguracion;
    }

    public JMenuItem getMnOscuro() {
        return mnOscuro;
    }

    public JMenuItem getMnClaro() {
        return mnClaro;
    }

    public JMenuItem getMnActualizar() {
        return mnActualizar;
    }

    public JMenuItem getMnRestaurar() {
        return mnRestaurar;
    }

    public JMenuItem getMnModificar() {
        return mnModificar;
    }
}

