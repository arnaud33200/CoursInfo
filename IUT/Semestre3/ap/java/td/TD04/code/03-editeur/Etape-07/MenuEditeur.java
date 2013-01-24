import java.awt.*;

public class MenuEditeur extends MenuBar
{
    public MenuItem menuQuitter ;
    public MenuItem menuNouveau ;
    public MenuItem menuAPropos ;

    public MenuEditeur ()
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
    }
}