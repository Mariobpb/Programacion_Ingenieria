package vista;

import controlador.ControlVtnMenuPrincipal;

import java.awt.Font;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JPanel;


public class VtnMenuPrincipal {
    ControlVtnMenuPrincipal control = null;

    // Componentes visuales
    private JFrame vtn;
    private JPanel pnlPrinc;
    private JLabel lblTitulo;
    private JButton btnAlumno;
    private JButton btnDocente;

    public VtnMenuPrincipal() {
        vtn = new JFrame("Sistema Escuela");
        vtn.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vtn.setSize(300, 150);
        vtn.setResizable(false);
        vtn.setLocationRelativeTo(null);
    }

    public void dibujarVentana() {
        // Creación de los componentes
        lblTitulo = new JLabel("Sistema Escolar");
        btnAlumno = new JButton("Alumnos");
        btnDocente = new JButton("Docentes");
        pnlPrinc = new JPanel();
        
        // Configuración del título
        lblTitulo.setFont(new Font("Cantarell", Font.ITALIC | Font.BOLD, 26));
        pnlPrinc.setLayout(new FlowLayout());
        pnlPrinc.add(lblTitulo);
        pnlPrinc.add(btnAlumno);
        pnlPrinc.add(btnDocente);
        vtn.add(pnlPrinc);

        control = new ControlVtnMenuPrincipal(this);
        vtn.setVisible(true);
    }

    public JFrame getVtn() {
        return vtn;
    }

    public JButton getBtnAlumno() {
        return btnAlumno;
    }

    public JButton getBtnDocente() {
        return btnDocente;
    }
}


