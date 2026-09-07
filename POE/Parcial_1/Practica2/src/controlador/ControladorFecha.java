package controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import modelo.Fecha;
import vista.VentanaFecha;

public class ControladorFecha implements ActionListener{
    private Fecha fecha;
    private VentanaFecha vtn;

    public ControladorFecha(Fecha fecha, VentanaFecha vtn) {
        this.fecha = fecha;
        this.vtn = vtn;

        this.vtn.getBtnVerificar().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
