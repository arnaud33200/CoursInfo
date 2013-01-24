/*
  Création d'une fenêtre
  par HERITAGE.
  
  1- ajout d'un Canvas
  2- ajout d'une ellipse

  l'ellipse apparait une fraction de seconde

 */
import java.awt.*;
import javax.swing.*;

public class Fenetre extends JFrame 
{
    private Canvas can;

    public Fenetre(String titre)
    {
	super(titre);
	setBounds(0,0,400,200);
	can=new Canvas();
	add(can,"Center");
	setVisible(true);
	Graphics g = can.getGraphics();
	g.setColor(Color.black);
	g.drawOval(160,10,65,100);
	// g.drawLine(40,40,40,160);
	// g.drawRect(300,40,40,60);
	// pack();
    }
}
