import java.util.*;
import java.awt.*;

class Dessin extends Vector 
{
    public void ajouterDroite(Droite droite)
    {
	addElement(droite);
    }
    public void defaire()
    {
	if(!isEmpty())
	    removeElement(lastElement());
    }
    public void efface()
    {
	removeAllElements();
    }
    public void dessine(Graphics g)
    {
	for(Enumeration e = elements();e.hasMoreElements();)
	    ((Droite)e.nextElement()).dessine(g);
    }
}