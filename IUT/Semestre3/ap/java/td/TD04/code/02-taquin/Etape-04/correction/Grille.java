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

    private int i_null;
    private int j_null;

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
	j_null = nbLignes-1;
	i_null = nbColonnes-1;
	melanger();
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
	//	super.paint(g);

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
    
    public void deplacerJeton(int x,int y)
    {
	// trouver le jeton 

	int i_jeton=x-abs;
	int j_jeton=y-ord;
	if( i_jeton >= 0  && i_jeton < nbColonnes*largeurColonne && 
	    j_jeton >= 0  && j_jeton < nbLignes*hauteurLigne)
	    {
		i_jeton/=largeurColonne;
		j_jeton/=hauteurLigne;
	    }
	else 
	    return;

	//verifier l'adjacence et si ok permutter

	if((i_null == i_jeton && j_null == j_jeton+1) ||
	   (i_null == i_jeton && j_null == j_jeton-1) ||
	   (i_null == i_jeton+1 && j_null == j_jeton) ||
	   (i_null == i_jeton-1 && j_null == j_jeton))
	    {
		Jeton tmp = jetons[j_jeton][i_jeton];
		jetons[j_jeton][i_jeton]=null;
		jetons[j_null][i_null]=tmp;
		jetons[j_null][i_null].setAbs(abs+i_null*largeurColonne);
		jetons[j_null][i_null].setOrd(ord+j_null*hauteurLigne);
		i_null=i_jeton;
		j_null=j_jeton;
	    }
    }
    
    public void melanger()
    {
	for(int i=0;i<1000;i++)
	    {
		int x_s = (int)(Math.random()*nbColonnes);
		int y_s = (int)(Math.random()*nbLignes);	
		int x_d = (int)(Math.random()*nbColonnes);
		int y_d = (int)(Math.random()*nbLignes);
		if(jetons[y_s][x_s] != null && jetons[y_d][x_d] != null)
		    {
			// Pas très objet tout ça !
			Color c = jetons[y_s][x_s].getCouleur();
			int num = jetons[y_s][x_s].getNumero();
			jetons[y_s][x_s].setCouleur(jetons[y_d][x_d].getCouleur());
			jetons[y_s][x_s].setNumero(jetons[y_d][x_d].getNumero());
			jetons[y_d][x_d].setCouleur(c);
			jetons[y_d][x_d].setNumero(num);
			
		    }
	    }
    }
}