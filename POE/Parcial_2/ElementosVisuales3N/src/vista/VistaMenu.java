package vista;

import controlador.ControladorMenu;

import javax.swing.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.Objects;

import static java.awt.event.KeyEvent.VK_A;

public class VistaMenu {
    private ControladorMenu control;

    private JFrame vtn = null;
    private JMenuBar mnBarra = null;
    private JMenu mnArchivo = null;
    private JMenu mnExportar = null;

    private JMenuItem mnAbrir = null;
    private JMenuItem mnSalir = null;
    private JMenuItem mnPdf = null;
    private JMenuItem mnDoc = null;

    private ImageIcon imgAbrir = null;
    private ImageIcon imgSalir = null;
    private ImageIcon imgPdf = null;
    private ImageIcon imgDoc = null;

    public VistaMenu() {
        vtn = new JFrame("Ejemplo de Menu de Java");
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn.setSize(500, 300);
        vtn.setResizable(false);
    }

    public void dibujarVentana() {
        mnBarra = new JMenuBar();
        mnArchivo = new JMenu("Archivo");
        mnExportar = new JMenu("Exportar");

        mnAbrir = new JMenuItem("Abrir");
        mnSalir = new JMenuItem("Salir");

        mnPdf = new JMenuItem("PDF");
        mnDoc = new JMenuItem("Doc");

        cargarImagenes();

        mnAbrir.setIcon(imgAbrir);
        mnSalir.setIcon(imgSalir);
        mnPdf.setIcon(imgPdf);
        mnDoc.setIcon(imgDoc);

        mnAbrir.setAccelerator(
                KeyStroke.getKeyStroke(
                        KeyEvent.VK_A,
                        InputEvent.CTRL_DOWN_MASK
                )
        );

        mnSalir.setAccelerator(
                KeyStroke.getKeyStroke(
                        KeyEvent.VK_S,
                        InputEvent.CTRL_DOWN_MASK
                )
        );

        mnExportar.add(mnPdf);
        mnExportar.add(mnDoc);

        mnArchivo.add(mnAbrir);
        mnArchivo.add(mnExportar);
        mnArchivo.add(mnSalir);

        mnBarra.add(mnArchivo);

        vtn.setJMenuBar(mnBarra);

        control = new ControladorMenu(this);

        vtn.setVisible(true);
    }

    public void cargarImagenes() {
        imgAbrir = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnAbrir.png")));
        imgSalir = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnSalir.png")));
        imgPdf = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnPDF.png")));
        imgDoc = new ImageIcon(Objects.requireNonNull(getClass().getResource("/imagenes/mnDoc.png")));
    }

    public JMenuItem getMnAbrir() {
        return mnAbrir;
    }

    public JMenuItem getMnSalir() {
        return mnSalir;
    }

    public JMenuItem getMnPdf() {
        return mnPdf;
    }

    public JMenuItem getMnDoc() {
        return mnDoc;
    }
}
