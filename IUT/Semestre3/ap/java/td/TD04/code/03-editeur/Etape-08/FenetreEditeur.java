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


	barreEtat = new BarreEtat();
	barreEtat.afficheMessage("Message d'exemple");
	add(barreEtat,"South");

	zoneGraphique= new ZoneGraphique(barreEtat);
	add(zoneGraphique,"Center");
	
	barreOutils = new BarreOutils(zoneGraphique);
	add(barreOutils,"North");


	menuEditeur = new MenuEditeur();
	setMenuBar(menuEditeur);

	addWindowListener(new GestionnaireFenetre());
	
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
