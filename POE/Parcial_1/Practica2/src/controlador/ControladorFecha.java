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

        this.vtn.getBtnImpFechaCorta().addActionListener(this);
        this.vtn.getBtnImpFechaLarga().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == vtn.getBtnImpFechaCorta()){
            actualizarFecha();
            if (fecha.validarFecha() == 1) {
                vtn.getLblRes().setText(fecha.imprimirFechaCorta());
            } else {
                vtn.getLblRes().setText("ERROR: Fecha Invalida");
            }
        }
        if(e.getSource() == vtn.getBtnImpFechaLarga()){
            actualizarFecha();
            if (fecha.validarFecha() == 1) {
                vtn.getLblRes().setText(fecha.imprimirFechaLarga());
            } else {
                vtn.getLblRes().setText("ERROR: Fecha Invalida");
            }
        }
    }

    private void actualizarFecha(){
        fecha.setDia(Integer.parseInt(vtn.getTxtDia().getText()));
        fecha.setMes(Integer.parseInt(vtn.getTxtMes().getText()));
        fecha.setAnio(Integer.parseInt(vtn.getTxtAnio().getText()));
    }
}
