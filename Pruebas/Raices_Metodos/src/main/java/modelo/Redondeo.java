package modelo;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class Redondeo {
    public double redondear(double x){
        BigDecimal bd = new BigDecimal(x);
        bd = bd.setScale(4, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }
}
