import java.awt.*;
import java.awt.event.*;


public class ZoneGraphique extends Canvas implements MouseMotionListener
{
    private BarreEtat barreEtat;
    private Color couleurChoisie = Color.blue;
    
    public ZoneGraphique(BarreEtat barreEtat)
    {
	setBackground(Color.white);
	setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
	this.barreEtat = barreEtat;
	addMouseMotionListener(this); 
	// une ZoneGraphique est une source d'�v�nements de type MouseEvent
	// le this en parametre signifie que c'est la 
	// zone graphique qui g�re ce type d'�v�nement.
	// d'o� l'implements

	addMouseListener(new GestionnaireClick(this));
     }
    
    /*
      Rappel de l'interface MouseMotionListener :
      
      public interface MouseMotionListener extends EventListener 
      {
         public void mouseDragged (MouseEvent e);
         public void mouseMoved (MouseEvent e);
      }
    */

    public void mouseMoved(MouseEvent e)
    {
	barreEtat.afficheCoord(e.getX(),e.getY());
    }

    public void mouseDragged(MouseEvent e)
    {
	barreEtat.afficheCoord(e.getX(),e.getY());
    }
    
    public void initieDroite(int x,int y)
    {
	barreEtat.afficheMessage("initier droite en ( " + x + " , " + y + " )");
    }

    public void termineDroite(int x,int y)
    {
	barreEtat.afficheMessage("terminer droite en ( " + x + " , " + y + " )");
    }
}