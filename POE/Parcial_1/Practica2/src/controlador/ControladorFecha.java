package controlador;

public class ControladorFecha implements ActionListener{
    private Fecha fecha;
    private VentanaFecha vtn;

    public ControladorFecha(Fecha fecha, VentanaFecha vtn) {
        this.fecha = fecha;
        this.vtn = vtn;

        this.vtn.addActionListener(this);
    }
}
