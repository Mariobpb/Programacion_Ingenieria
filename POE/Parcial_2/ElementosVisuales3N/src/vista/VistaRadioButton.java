package vista;


import controlador.ControlRadioButton;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JButton;
import javax.swing.ButtonGroup;
import javax.swing.BoxLayout;
import java.awt.BorderLayout;
import java.awt.FlowLayout;

public class VistaRadioButton {
    private JFrame vista = null;
    private JPanel panelPrin = null;
    private JPanel panelNor = null;
    private JPanel panelCen = null;
    private JPanel panelSur = null;

    private JLabel lblTitulo = null;
    private JLabel lblCarreras = null;
    private JLabel lblResultado = null;
    private JRadioButton rdbIds = null;
    private JRadioButton rdbIdesi = null;
    private JRadioButton rdbMec = null;
    private JRadioButton rdbInd = null;
    private JButton btnElegir = null;

    private ButtonGroup btngCarreras = new ButtonGroup();

    private ControlRadioButton control = null;


    public VistaRadioButton(){
        vista = new JFrame("Ejemplo Radio Button");
        vista.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vista.setSize(600, 400);
        vista.setResizable(false);
    }
    
    public void dibujarVentana(){
        panelPrin = new JPanel();
        panelNor = new JPanel();
        panelCen = new JPanel();
        panelSur = new JPanel();
        lblTitulo = new JLabel("Selecciona tu carrera");
        lblCarreras = new JLabel("Elije tu ingenieria");
        lblResultado = new JLabel();
        rdbIds = new JRadioButton("IDS");
        rdbIdesi = new JRadioButton("IDESI");
        rdbMec = new JRadioButton("Mecatronica");
        rdbInd = new JRadioButton("Industrial");
        btnElegir = new JButton("Elegir");
        btngCarreras = new ButtonGroup();


        btngCarreras.add(rdbIds);
        btngCarreras.add(rdbIdesi);
        btngCarreras.add(rdbMec);
        btngCarreras.add(rdbInd);

        panelPrin.setLayout(new BorderLayout());
        panelNor.setLayout(new FlowLayout());
        panelCen.setLayout(new BoxLayout(panelCen, BoxLayout.Y_AXIS));
        panelSur.setLayout(new FlowLayout());


        panelNor.add(lblTitulo);

        panelCen.add(lblCarreras);
        panelCen.add(rdbIds);
        panelCen.add(rdbMec);
        panelCen.add(rdbIdesi);
        panelCen.add(rdbInd);

        panelSur.add(btnElegir);
        panelSur.add(lblResultado);


        panelPrin.add(panelNor, BorderLayout.NORTH);
        panelPrin.add(panelCen, BorderLayout.CENTER);
        panelPrin.add(panelSur, BorderLayout.SOUTH);

        vista.add(panelPrin);
        vista.setVisible(true);
        control = new ControlRadioButton(this);
    }

    public JButton getBtnElegir() {
        return btnElegir;
    }

    public JRadioButton getRdbIds() {
        return rdbIds;
    }

    public JRadioButton getRdbIdesi() {
        return rdbIdesi;
    }

    public JRadioButton getRdbMec() {
        return rdbMec;
    }

    public JRadioButton getRdbInd() {
        return rdbInd;
    }

    public JLabel getLblResultado() {
        return lblResultado;
    }
}
