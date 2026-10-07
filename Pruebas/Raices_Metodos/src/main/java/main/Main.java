package main;

import modelo.DatosEntrada;
import modelo.Funcion;
import modelo.metodos.Secante;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DatosEntrada datosEntrada = null;
        Funcion funcion = null;
        String expresion = null;
        double x0 = -1000, x1 = -1000, tolerancia = -1000;

        while (funcion == null || x0 == -1000 || x1 == -1000 || tolerancia == -1000) {
            //expresion = "x^2 - 2";
            System.out.print("\nf(x) = ");
            expresion = scanner.nextLine();
            try {
                funcion = new Funcion(expresion);
                System.out.print("x0 = ");
                x0 = scanner.nextDouble();
                System.out.print("x1 = ");
                x1 = scanner.nextDouble();
                System.out.print("tolerancia = ");
                tolerancia = scanner.nextDouble();
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
        datosEntrada = new DatosEntrada(funcion, x0, x1, tolerancia);
        Secante secante = new Secante(datosEntrada);
        secante.encontrarRaices();
    }
}