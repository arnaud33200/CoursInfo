/*
  
  Quand un container s'affiche ou se ré-affiche, il appelle sa méthode
  paint(Graphics g) qui appelle la méthode paint(Graphics g) de chacun
  des composants présents dans le container.

 */

import java.awt.*;

public class Dessin extends Canvas
{
    private Color couleur;

    public void setColor(Color couleur)
    {
	this.couleur=couleur;
    }

    public void paint (Graphics g) 
    {
	super.paint(g);

	g.setColor(couleur);
	g.drawOval(10,10,150,100);
    }
}
