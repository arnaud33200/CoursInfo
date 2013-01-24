/*
  
  Quand un container s'affiche ou se r�-affiche, il appelle sa m�thode
  paint(Graphics g) qui appelle la m�thode paint(Graphics g) de chacun
  des composants pr�sents dans le container.

 */

import java.awt.*;

public class Dessin extends Canvas
{
    public void paint (Graphics g) 
    {
	super.paint(g);

	g.setColor(Color.black);
	g.drawOval(10,10,150,100);
    }
}
