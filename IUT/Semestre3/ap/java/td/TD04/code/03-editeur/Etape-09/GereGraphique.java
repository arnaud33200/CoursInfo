import java.awt.event.*;
import java.awt.*;

public class GereGraphique implements ActionListener
{
    public static final int QUITTER = 0;
    public static final int NOUVEAU = 1;
    public static final int DEFAIRE = 2;
    public static final int APROPOS = 3;

    private int id;
    private ZoneGraphique zoneGraphique;

    public GereGraphique(int id,ZoneGraphique zoneGraphique)
    {
	this.id = id;
	this.zoneGraphique = zoneGraphique;
    }

    public void actionPerformed(ActionEvent e)
    {
	switch(id)
	    {
	    case QUITTER : System.exit(0);
		break;
	    case NOUVEAU : zoneGraphique.efface();
		break;
	    case DEFAIRE : zoneGraphique.defaire();
		break;
	    case APROPOS : System.out.println("A propos");
		break;
	    }
    }
    
}