/*
  Création d'une fenêtre contenant :
  - 2 boutons 
  - 1 texte

  par HERITAGE.

 */
import java.awt.*;
import javax.swing.*;

public class Fenetre extends JFrame 
{
    private JButton b1, b2;
    private JLabel lbl;

    public Fenetre(String titre)
    {
	super(titre);
	setBounds(0,0,400,200);
	b1=new JButton("B1");
	b2=new JButton("B2");
	lbl=new JLabel("texte quelconque");
	add(b1,"North");
	add(lbl,"Center");
	add(b2,"South");
	setVisible(true);
	// pack();
    }
}
