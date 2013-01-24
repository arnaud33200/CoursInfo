import java.awt.*;

public class BarreOutils extends Panel
{
    /*
    public class Bouton extends Button
    {
	public Bouton (String libelle)
	{
	    super(libelle);
	}
	public Dimension getPreferredSize()
	{
	    return new Dimension(80,25);
	}
    }
    */
    
    private ZoneGraphique zoneGraphique;
    private Button boutonEffacer;
    private Button boutonEffacerTout;
    private Button boutonQuitter;
    
    public BarreOutils(ZoneGraphique zoneGraphique)
    {
	
	/*
	// il faudrait ajouter la gestion des évènements liés au choix 
	String libelleCouleurs [] = {"Bleu","Rouge","Jaune","vert"};
	Color couleurs [] = {Color.blue,Color.red,Color.yellow,Color.green};
	Choice listeCouleurs = new Choice();
	setBackground(Color.lightGray);
	for(int i=0;i<libelleCouleurs.length;i++)
	    listeCouleurs.addItem(libelleCouleurs[i]);
	listeCouleurs.select(0);
	add(listeCouleurs);
	*/

	boutonEffacer = new Button("Effacer");
	add(boutonEffacer);
	boutonEffacer.addActionListener(new GereGraphique(GereGraphique.DEFAIRE,
							  zoneGraphique));


	boutonEffacerTout = new Button("Effacer tout");
	add(boutonEffacerTout);
	boutonEffacerTout.addActionListener(new GereGraphique(GereGraphique.NOUVEAU,
							  zoneGraphique));

	boutonQuitter = new Button("Quitter");
	add(boutonQuitter);
	boutonQuitter.addActionListener(new GereGraphique(GereGraphique.QUITTER,
							  zoneGraphique));
	
	/*
	add(new Bouton("Effacer"));
	add(new Bouton("Effacer tout"));
	add(new Bouton("Quitter"));
	*/

	this.zoneGraphique=zoneGraphique;;
    }
}