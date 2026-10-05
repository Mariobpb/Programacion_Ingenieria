package controlador;

import vista.Ventana1;
import vista.Ventana2;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControlVentana1 implements ActionListener {
    private Ventana1 vtn1 = null;
    private Ventana2 vtn2 = null;

    public ControlVentana1(Ventana1 vtn1) {
        this.vtn1 = vtn1;
        this.vtn1.getBtnIrAvtn2().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vtn1.getBtnIrAvtn2()) {
            if (vtn2 == null) {
                vtn2 = new Ventana2(vtn1);
                vtn2.dibujarVentana();
            }
            vtn2.getVtn2().setVisible(true);
            vtn1.getVtn1().setVisible(false);
        }
    }
}
