package controlador;

import modelo.Empleado;
import vista.VentanaEmpleado;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ControladorEmpleado implements ActionListener {
    private Empleado empleado;
    private VentanaEmpleado vtnEmpleado;

    public ControladorEmpleado(Empleado empleado, VentanaEmpleado vtnEmpleado) {
        this.empleado = empleado;
        this.vtnEmpleado = vtnEmpleado;

        this.vtnEmpleado.getBtnSalarioMensual().addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == vtnEmpleado.getBtnSalarioMensual()) {
            empleado.setNombre(vtnEmpleado.getTxtNombre().getText());
            empleado.setPuesto(vtnEmpleado.getTxtPuesto().getText());
            empleado.setPagoHora(Double.parseDouble(vtnEmpleado.getTxtPagoHora().getText()));
            empleado.setHorasTrabajadasMes(Double.parseDouble(vtnEmpleado.getTxtHorasTrabajadasMes().getText()));
            empleado.setSalarioMensual(empleado.obtenerSalarioMensual());

            vtnEmpleado.getLblInfo().setText(empleado.imprimirDatosTrabajador());
        }
    }
}
