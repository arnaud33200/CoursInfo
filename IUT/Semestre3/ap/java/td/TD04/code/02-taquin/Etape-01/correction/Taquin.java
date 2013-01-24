import java.awt.*;
import javax.swing.*;

public class Taquin extends JFrame {
    private Grille grille;
    private int nbLignesTaquin;
    private int nbColonnesTaquin;
    final static int largeurFenetre = 400;
    final static int hauteurFenetre = 400;

    public Taquin(String titre){
	super(titre);
	
	nbLignesTaquin = 3;
	nbColonnesTaquin = 3;
	
	setBounds(0,0,largeurFenetre,hauteurFenetre);
	int x_0 = (largeurFenetre - Grille.getLargeurColonne()*nbColonnesTaquin)/2;
	int y_0 = (hauteurFenetre - Grille.getHauteurLigne()*nbLignesTaquin)/2;
	grille=new Grille(nbLignesTaquin,nbColonnesTaquin,x_0,y_0);
	add(grille,"Center");
	setVisible(true);
    }
    
    public static void main (String args []){
	new Taquin("Jeu de Taquin");
    }
}
