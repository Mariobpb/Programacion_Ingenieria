package controlador;

import vista.VistaRadioButton;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLOutput;

public class ControlRadioButton implements ActionListener {
    VistaRadioButton vista = null;

    public ControlRadioButton(VistaRadioButton vista) {
        this.vista = vista;

        this.vista.getRdbIds().addActionListener(this);
        this.vista.getRdbIdesi().addActionListener(this);
        this.vista.getRdbMec().addActionListener(this);
        this.vista.getRdbInd().addActionListener(this);
        this.vista.getBtnElegir().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vista.getRdbIds()) {
            System.out.println("IDS");
            vista.getLblResultado().setText("IDS");
        } else if (e.getSource() == vista.getRdbIdesi()) {
            System.out.println("IDESI");
            vista.getLblResultado().setText("IDESI");
        } else if (e.getSource() == vista.getRdbMec()) {
            System.out.println("MECATRONICA");
            vista.getLblResultado().setText("MECATRONICA");
        } else if (e.getSource() == vista.getRdbInd()) {
            System.out.println("INDUSTRIAL");
            vista.getLblResultado().setText("INDUSTRIAL");
        }
        else if (e.getSource() == vista.getBtnElegir()) {
            System.out.println("ELEGIR");
            if (vista.getRdbIds().isSelected()) {
                System.out.println("Carrera IDS seleccionado");
            }
        }
    }
}
