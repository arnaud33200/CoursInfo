import java.awt.*;

public class MenuEditeur extends MenuBar
{
    private MenuItem menuQuitter;
    private MenuItem menuNouveau;
    private MenuItem menuAPropos;
    private ZoneGraphique zoneGraphique;

    public MenuEditeur (ZoneGraphique zoneGraphique)
    {
	Menu menuFichier = new Menu("Fichier");
	menuNouveau = new MenuItem("Nouveau");
	menuQuitter = new MenuItem("Quitter");
	menuFichier.add(menuNouveau);
	menuFichier.addSeparator();
	menuFichier.add(menuQuitter);
	Menu menuAide = new Menu("Aide");
	menuAPropos = new MenuItem("A Propos");
	menuAide.add(menuAPropos);
	add(menuFichier);
	setHelpMenu(menuAide);

	this.zoneGraphique = zoneGraphique;
	menuQuitter.addActionListener(new GereGraphique(GereGraphique.QUITTER,
							zoneGraphique));
	menuNouveau.addActionListener(new GereGraphique(GereGraphique.NOUVEAU,
							zoneGraphique));
	menuAPropos.addActionListener(new GereGraphique(GereGraphique.APROPOS,
							zoneGraphique));
    }
}