import java.awt.*;
import javax.swing.*;

public class Grille extends Canvas
{
    // attributs, champs
    private int nbLignes;
    private int nbColonnes;
    
    private int abs;
    private int ord;
    
    final static int largeurColonne = 40;
    final static int hauteurLigne   = 40;

    // constructeurs
    public Grille(int nbLignes, int nbColonnes,
		  int abs, int ord)
    {
	this.nbLignes = nbLignes;
	this.nbColonnes = nbColonnes;
	this.abs = abs;
	this.ord = ord;
    }

    // "geteurs" / "seteurs"
    public int getNbLignes()
    {
	return nbLignes;
    }
    public int getNbColonnes()
    {
	return nbColonnes;
    }
    public int getAbs()
    {
	return abs;
    }
    public int getOrd()
    {
	return ord;
    }
    public static int getLargeurColonne()
    {
	return largeurColonne;
    }
    public static int getHauteurLigne()
    {
	return hauteurLigne;
    }
    public void setNbLignes(int nbLignes)
    {
	this.nbLignes = nbLignes;
    }
    public void setNbColonnes(int nbColonnes)
    {
	this.nbColonnes = nbColonnes;
    }
    public void setAbs(int abs)
    {
	this.abs = abs;
    }
    public void setOrd(int ord)
    {
	this.ord = ord;
    }
    
    // Override paint
    public void paint(Graphics g)
    {
	super.paint(g);
	g.setColor(Color.black);

	// dessin de la grille 
	for(int i=0;i<nbLignes;i++)
	    {
		for(int j=0;j<nbColonnes;j++)
		    {
			g.drawRect(abs+j*largeurColonne,ord+i*hauteurLigne,
				   largeurColonne,hauteurLigne);
		    }
	    }
    }
}