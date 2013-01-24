import java.awt.*;
import javax.swing.*;

public class Fenetre extends JFrame 
{
    private JButton b1, b2;
    private Dessin dessin;
    
    public Fenetre(String titre)
    {
	super(titre);
	setBounds(0,0,400,200);
	b1=new JButton("B1");
	b2=new JButton("B2");
	dessin=new Dessin();
	b1.addActionListener(new ChangeCouleur(Color.red,dessin));
	b2.addActionListener(new ChangeCouleur(dessin.getForeground(),dessin));
	add(b1,"North");
	add(dessin,"Center");
	add(b2,"South");
	setVisible(true);
    }
}
