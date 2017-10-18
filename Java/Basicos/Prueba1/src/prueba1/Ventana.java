
package prueba1;
import java.awt.FlowLayout;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
/**
 *
 * @author Horacio
 */
public class Ventana extends JFrame{
    
    public Ventana()
    {
        setBounds(50, 50, 500, 500);
        JLabel l = new JLabel("Escribe tu nombre");
        JTextField nombre = new JTextField("          ");
        JButton boton = new JButton("Saludo");
        JLabel label = new JLabel("");
        nombre.setBounds(new Rectangle(100,100));
        setLayout(new FlowLayout());
        
        add(l);
        add(nombre);
        add(boton);
        add(label);
        boton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nombre.getText();
                label.setText("Hola "+ name);
            }
        });
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    public static void main(String[] args) {
        Ventana v = new Ventana();
        
    }
}
