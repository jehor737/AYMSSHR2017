package prueba1;

import java.util.Scanner;

public class Prueba1 {
    protected int edad;
    protected String nombre;
    public Prueba1(int edad, String nombre)
    {
        this.edad = edad;
        this.nombre = nombre;
                
    }
    public int getEdad(){
        return edad;
    }
    
    protected void printName()
    {
        System.out.println("Mi nombre es: "+ nombre);
    }
          
    
    /*public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Ingresa tu nombre");
        String nombre = s.nextLine();
        System.out.println("Ingresa tu edad");
        int edad= s.nextInt();
        Prueba1 ejemplo = new Prueba1(edad, nombre);
        ejemplo.printName();
        System.out.println("Mi edad es " + ejemplo.getEdad());
    }*/
}
