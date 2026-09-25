package vista;

import controlador.ControlVentana;

import javax.swing.*;
import java.awt.*;

public class VistaVentana {
    private JFrame vista = null;
    private JPanel panelPrincipal = null;
    private JPanel panelNorte = null;
    private JPanel panelCentral = null;
    private JPanel panelSur = null;

    private JLabel lblTitulo = null;

    private JPanel panelIng = null;
    private JPanel panelTurno = null;
    private JPanel panelPago = null;

    private JLabel lblTituloIng = null;
    private ButtonGroup btngIng = null;
    private JRadioButton rdbIDS = null;
    private JRadioButton rdbIDESI = null;
    private JRadioButton rdbMec = null;
    private JRadioButton rdbInd = null;

    private JLabel lblTituloTurno = null;
    private ButtonGroup btngTurno = null;
    private JRadioButton rdbMatutino = null;
    private JRadioButton rdbVespertino = null;

    private JLabel lblTituloPago = null;
    private ButtonGroup btngPago = null;
    private JRadioButton rdbEfectivo = null;
    private JRadioButton rdbDebito = null;
    private JRadioButton rdbCredito = null;

    private JButton btnElegir = null;
    private JLabel lblResultado = null;

    private Font fuenteTitulo = null;
    private Font fuenteTituloSeccion = null;
    private Font fuenteSeccion = null;

    private ControlVentana control = null;

    public VistaVentana() {
        vista = new JFrame("Practica_01");
        vista.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        vista.setResizable(false);
    }

    public void dibujarVentana(){
        instanciarComponentes();
        definirLayout();
        configurarComponentes();
        anadirComponentes();

        vista.pack();
        vista.setLocationRelativeTo(null);

        control = new ControlVentana(this);

        vista.setVisible(true);
    }

    private void instanciarComponentes(){
        panelPrincipal = new JPanel();
        panelNorte = new JPanel();
        panelCentral = new JPanel();
        panelSur = new JPanel();
        panelIng = new JPanel();
        panelTurno = new JPanel();
        panelPago = new JPanel();

        lblTitulo = new JLabel("INSCRIPCIÓN DE CARRERA");

        lblTituloIng = new JLabel("Elige tu ingeniería");
        btngIng = new ButtonGroup();
        rdbIDS = new JRadioButton("IDS");
        rdbIDESI = new JRadioButton("IDESI");
        rdbMec = new JRadioButton("Mecatrónica");
        rdbInd = new JRadioButton("Industrial");

        lblTituloTurno = new JLabel("Elige tu Turno");
        btngTurno = new ButtonGroup();
        rdbMatutino = new JRadioButton("Matutino");
        rdbVespertino = new JRadioButton("Vespertino");

        lblTituloPago = new JLabel("Elige tu Pago");
        btngPago = new ButtonGroup();
        rdbEfectivo = new JRadioButton("Efectivo");
        rdbDebito = new JRadioButton("Debito");
        rdbCredito = new JRadioButton("Credito");

        btnElegir = new JButton("ELEGIR");
        lblResultado = new JLabel();

        fuenteTitulo = new Font("Arial", Font.BOLD, 30);
        fuenteTituloSeccion = new Font("Arial", Font.BOLD, 20);
        fuenteSeccion = new Font("Arial", Font.PLAIN, 17);
    }

    private void definirLayout() {
        panelPrincipal.setLayout(new BorderLayout(0, 10));
        panelNorte.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 20));
        panelCentral.setLayout(new FlowLayout(FlowLayout.CENTER, 80, 50));
        panelSur.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 20));
        panelIng.setLayout(new BoxLayout(panelIng, BoxLayout.Y_AXIS));
        panelTurno.setLayout(new BoxLayout(panelTurno, BoxLayout.Y_AXIS));
        panelPago.setLayout(new BoxLayout(panelPago, BoxLayout.Y_AXIS));
    }

    private void configurarComponentes() {
        // Etiquetas
        rdbIDS.setActionCommand("IDS");
        rdbIDESI.setActionCommand("IDESI");
        rdbMec.setActionCommand("MECATRONICA");
        rdbInd.setActionCommand("INDUSTRIAL");

        rdbMatutino.setActionCommand("MATUTINO");
        rdbVespertino.setActionCommand("VESPERTINO");

        rdbEfectivo.setActionCommand("EFECTIVO");
        rdbDebito.setActionCommand("DEBITO");
        rdbCredito.setActionCommand("CREDITO");

        // Fuentes
        lblTitulo.setFont(fuenteTitulo);

        lblTituloIng.setFont(fuenteTituloSeccion);
        rdbIDS.setFont(fuenteSeccion);
        rdbIDESI.setFont(fuenteSeccion);
        rdbMec.setFont(fuenteSeccion);
        rdbInd.setFont(fuenteSeccion);

        lblTituloTurno.setFont(fuenteTituloSeccion);
        rdbMatutino.setFont(fuenteSeccion);
        rdbVespertino.setFont(fuenteSeccion);

        lblTituloPago.setFont(fuenteTituloSeccion);
        rdbEfectivo.setFont(fuenteSeccion);
        rdbDebito.setFont(fuenteSeccion);
        rdbCredito.setFont(fuenteSeccion);
    }
    private void anadirComponentes(){
        // Seccion Ingenieria
        btngIng.add(rdbIDS);
        btngIng.add(rdbIDESI);
        btngIng.add(rdbMec);
        btngIng.add(rdbInd);

        panelIng.add(lblTituloIng);
        panelIng.add(rdbIDS);
        panelIng.add(rdbIDESI);
        panelIng.add(rdbMec);
        panelIng.add(rdbInd);

        // Seccion Turno
        btngTurno.add(rdbMatutino);
        btngTurno.add(rdbVespertino);

        panelTurno.add(lblTituloTurno);
        panelTurno.add(rdbMatutino);
        panelTurno.add(rdbVespertino);

        // Seccion Metodo de pago
        btngPago.add(rdbEfectivo);
        btngPago.add(rdbDebito);
        btngPago.add(rdbCredito);

        panelPago.add(lblTituloPago);
        panelPago.add(rdbEfectivo);
        panelPago.add(rdbDebito);
        panelPago.add(rdbCredito);

        // Panel principal
        panelNorte.add(lblTitulo);

        panelCentral.add(panelIng);
        panelCentral.add(panelTurno);
        panelCentral.add(panelPago);

        panelSur.add(btnElegir);
        panelSur.add(lblResultado);

        panelPrincipal.add(panelNorte, BorderLayout.NORTH);
        panelPrincipal.add(panelCentral, BorderLayout.CENTER);
        panelPrincipal.add(panelSur, BorderLayout.SOUTH);

        vista.add(panelPrincipal);
    }

    public ButtonGroup getBtngIng() {
        return btngIng;
    }

    public ButtonGroup getBtngTurno() {
        return btngTurno;
    }

    public ButtonGroup getBtngPago() {
        return btngPago;
    }

    public JButton getBtnElegir() {
        return btnElegir;
    }

    public JLabel getLblResultado() {
        return lblResultado;
    }
}
