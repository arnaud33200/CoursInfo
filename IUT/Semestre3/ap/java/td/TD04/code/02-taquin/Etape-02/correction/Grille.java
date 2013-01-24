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

    private Jeton jetons [][];
    private int nbJetons;

    // constructeurs
    public Grille(int nbLignes, int nbColonnes,
		  int abs, int ord)
    {
	this.nbLignes = nbLignes;
	this.nbColonnes = nbColonnes;
	this.abs = abs;
	this.ord = ord;
	nbJetons = nbLignes * nbColonnes - 1;
	jetons = new Jeton[nbLignes][nbColonnes];
	int pas = 256/(nbJetons+2); // pas top...
	int num=0;
	for(int i=0;i<nbLignes;i++)
	    for(int j=0;j<nbColonnes;j++)
		{
		    jetons[i][j]=new Jeton(abs+j*largeurColonne,
					   ord+i*hauteurLigne,
					   num++,
					   new Color(100,num*pas,num*pas));
		}
	jetons[nbLignes-1][nbColonnes-1]=null;
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

	// dessin des jetons
	for(int i=0;i<nbLignes;i++)
	    for(int j=0;j<nbColonnes;j++)
		{
		    if(jetons[i][j]!=null)
			{
			    g.setColor(jetons[i][j].getCouleur());
			    g.fillRect(jetons[i][j].getAbs(),jetons[i][j].getOrd(), 
				       largeurColonne,hauteurLigne);
			    g.setColor(Color.BLACK);
			    g.drawString(""+jetons[i][j].getNumero(), 
					 (int)(jetons[i][j].getAbs()+largeurColonne/2), 
					 (int)(jetons[i][j].getOrd()+hauteurLigne/2));
			}
		}
	
	// dessin de la grille 
	g.setColor(Color.black);
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