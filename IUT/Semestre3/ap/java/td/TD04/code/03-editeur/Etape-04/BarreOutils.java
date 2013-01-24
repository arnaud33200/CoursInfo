import java.awt.*;

public class BarreOutils extends Panel
{
    public BarreOutils()
    {

	String libelleCouleurs [] = {"Bleu","Rouge","Jaune","vert"};
	Color couleurs [] = {Color.blue,Color.red,Color.yellow,Color.green};
	Choice listeCouleurs = new Choice();
	setBackground(Color.lightGray);
	for(int i=0;i<libelleCouleurs.length;i++)
	    listeCouleurs.addItem(libelleCouleurs[i]);
	listeCouleurs.select(0);
	add(listeCouleurs);
	add(new Button("Effacer"));
	add(new Button("Effacer tout"));
	add(new Button("Quitter"));
    }
}