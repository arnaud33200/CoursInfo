/*
  Création d'une fenêtre contenant
  - 2 boutons
  - 1 texte

  par DELEGATION
 
 */

import java.awt.*;
import javax.swing.*;

public class Fenetre 
{
    private JFrame frm;
    private JButton b1, b2;
    private JLabel lbl;
    
    public Fenetre(String titre)
    {
	frm=new JFrame(titre);
	frm.setBounds(0,0,400,200);
	b1=new JButton("B1");
	b2=new JButton("B2");
	lbl=new JLabel("texte quelconque");
	frm.add(b1,"North");
	frm.add(lbl,"Center");
	frm.add(b2,"South");
	frm.setVisible(true);
        //frm.pack();
    }
}
