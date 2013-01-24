import java.awt.*;
import java.awt.event.*;


public class GestionnaireClick extends MouseAdapter
{
    private ZoneGraphique zoneGraphique;

    public GestionnaireClick(ZoneGraphique zoneGraphique)
    {
	this.zoneGraphique = zoneGraphique;
    }
    
    public void mousePressed(MouseEvent e)
    {
	zoneGraphique.initieDroite(e.getX(),e.getY());
    }

    public void mouseReleased(MouseEvent e)
    {
	zoneGraphique.termineDroite(e.getX(),e.getY());
    }
}