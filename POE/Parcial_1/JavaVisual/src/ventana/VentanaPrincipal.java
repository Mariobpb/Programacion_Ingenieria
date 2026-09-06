package ventana;

import controlador.Control;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class VentanaPrincipal {
    // Se declara un objeto de JFrame
    private JFrame vtnPrincipal = null;
    private JButton btnAceptar = null;
    private JButton btnCancelar = null;
    private JButton btnBuscar = null;
    private JButton btnEliminar = null;
    private JButton btnInsertar = null;
    private JTextField txtDato1 = null;
    private JTextField txtDato2 = null;
    private JLabel lblRes = null;
    
    private Control ctrl = null;
    
    // Se declara  un metodo de la clase para dibujar la ventana
    
    public void dibujarVentana() {
        vtnPrincipal = new JFrame("Mi primer programa visual en Java");
        btnAceptar = new JButton("Sumar");
        btnCancelar = new JButton("Restar");
        btnBuscar = new JButton("Multiplicar");
        btnEliminar = new JButton("Dividir");
        btnInsertar = new JButton("Insertar");
        txtDato1 = new JTextField();
        txtDato2 = new JTextField();
        lblRes = new JLabel();
        ctrl = new Control(this);
        
        
        //vtnPrincipal.setLayout(new BorderLayout());
        vtnPrincipal.setLayout(new FlowLayout());
        
        vtnPrincipal.setSize(1000, 600);
        //vtnPrincipal.setResizable(false);
        vtnPrincipal.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //vtnPrincipal.add(btnAceptar,BorderLayout.CENTER);
        //vtnPrincipal.add(btnCancelar,BorderLayout.SOUTH);
        //vtnPrincipal.add(btnBuscar,BorderLayout.NORTH);
        //vtnPrincipal.add(btnEliminar,BorderLayout.WEST);
        //vtnPrincipal.add(btnInsertar,BorderLayout.EAST);
        txtDato1.setColumns(5);
        txtDato2.setColumns(5);
        
        vtnPrincipal.add(btnAceptar);
        vtnPrincipal.add(btnCancelar);
        vtnPrincipal.add(btnBuscar);
        vtnPrincipal.add(btnEliminar);
        vtnPrincipal.add(btnInsertar);
        vtnPrincipal.add(txtDato1);
        vtnPrincipal.add(txtDato2);
        vtnPrincipal.add(lblRes);
        vtnPrincipal.setVisible(true);
    }
    
    public JButton getBtnAceptar() {
        return btnAceptar;
    }

    public JButton getBtnCancelar() {
        return btnCancelar;
    }

    public JButton getBtnBuscar() {
        return btnBuscar;
    }

    public JButton getBtnEliminar() {
        return btnEliminar;
    }

    public JButton getBtnInsertar() {
        return btnInsertar;
    }

    public JTextField getTxtDato1() {
        return txtDato1;
    }

    public JTextField getTxtDato2() {
        return txtDato2;
    }

    public JLabel getLblRes() {
        return lblRes;
    }
    
    
    
}