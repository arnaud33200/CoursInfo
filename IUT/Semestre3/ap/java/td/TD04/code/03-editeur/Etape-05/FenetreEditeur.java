import java.awt.*;
import javax.swing.*;

public class FenetreEditeur extends Frame 
{
    final static int HTaille = 750;
    final static int VTaille = 450;

    private BarreOutils barreOutils;
    private BarreEtat barreEtat;
    private MenuEditeur menuEditeur;
    private ZoneGraphique zoneGraphique;

    public FenetreEditeur()
    {
	setTitle("Editeur Graphique");
	setSize(HTaille,VTaille);
	setBackground(Color.darkGray);
	setLayout(new BorderLayout(2,2));
	
	barreOutils = new BarreOutils();
	add(barreOutils,"North");

	zoneGraphique= new ZoneGraphique();
	add(zoneGraphique,"Center");

	barreEtat = new BarreEtat();
	barreEtat.afficheMessage("Message d'exemple");
	barreEtat.afficheCoord(0,0);
	add(barreEtat,"South");

	menuEditeur = new MenuEditeur();
	setMenuBar(menuEditeur);

	show();
    }    
    
    /*
    public Insets getInsets()
    {
	Insets normal = super.getInsets();
	return new Insets (normal.top+2,normal.left,normal.bottom,normal.right);
    }
    */
}
