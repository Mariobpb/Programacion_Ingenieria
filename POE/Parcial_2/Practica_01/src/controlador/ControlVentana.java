package controlador;

import modelo.Modelo;
import vista.VistaVentana;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlVentana implements ActionListener {
    private Modelo modelo;
    private VistaVentana ventana;

    public ControlVentana(VistaVentana ventana) {
        this.ventana = ventana;
        modelo = new Modelo();

        ventana.getBtnElegir().addActionListener(this);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ventana.getBtnElegir()){
            String ing = ventana.getBtngIng().getSelection().getActionCommand();
            String turno = ventana.getBtngTurno().getSelection().getActionCommand();
            String pago = ventana.getBtngPago().getSelection().getActionCommand();

            System.out.println(ing);
            System.out.println(turno);
            System.out.println(pago);

            modelo.setPrecio(modelo.calcularPrecio(ing, turno, pago));

            ventana.getLblResultado().setText(String.valueOf(modelo.getPrecio()));
        }
    }
}
