package controlador;

import vista.Ventana1;
import vista.Ventana2;

import java.awt.event.*;

public class ControlVentana2 implements ActionListener, WindowListener {
    private Ventana2 vtn2 = null;

    public ControlVentana2(Ventana2 vtn2) {
        this.vtn2 = vtn2;
        this.vtn2.getBtnIrAvtn1().addActionListener(this);

        this.vtn2.getVtn2().addWindowListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtn2.getBtnIrAvtn1()){
            vtn2.getVtn1().getVtn1().setVisible(true);
            vtn2.getVtn2().setVisible(false);
        }
    }

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        vtn2.getVtn1().getVtn1().setVisible(true);
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
}
