// Labyrinthe.java
import java.io.*;
import java.util.*;

public class LabyrintheDefaut implements Labyrinthe{
    protected int hauteur;
    protected int largeur;
    protected Salle[][] salles;
    protected Salle entree;
    protected Salle sortie;
    
    // cree le labyrinthe
    public void creerLabyrinthe(String file)	
    {
		// A parir d'un fichier !
		Scanner sc=null;
		try
		{
			sc = new Scanner(new File(file));
		}
		catch(Exception e)
		{
		}

		// les deux premiers entiers
		// hauteur largeur
		hauteur=sc.nextInt();
		largeur=sc.nextInt();
		salles = new Salle[hauteur][largeur];

		// les deux entiers suivants
		// coord entree
		int ligneEntree=sc.nextInt();
		int colonneEntree=sc.nextInt();
		entree = new Salle(ligneEntree,colonneEntree);
		
		// les deux entiers suivants
		// coord sortie
		int ligneSortie=sc.nextInt();
		int colonneSortie=sc.nextInt();
		sortie = new Salle(ligneSortie,colonneSortie);

		// on initialise la matrice
		// null signifie : salle non existante
		for(int i=0;i<hauteur;i++)
		{
			for(int j=0;j<largeur;j++)
			{
				salles[i][j]=null;
			}
		}
		
	// ajout des entree et sortie
		salles[ligneEntree][colonneEntree]=entree;
		salles[ligneSortie][colonneSortie]=sortie;

	// ajout des autres salles
		while(sc.hasNext())
		{
			int ligne=sc.nextInt();
			int colonne=sc.nextInt();
			salles[ligne][colonne]=new Salle(ligne,colonne);
		}
    }
    
/// place bob a l'entree du labyrinthe
    public void entrer(Personnage bob)
    {
		bob.aller(entree);
    }

/// dit si bob est sorti
    public boolean sortir(Personnage bob)
    {
		return sortie.equals(bob.position());
    }

/// renvoie les salles accessibles par bob
    public Collection<Salle> sallesAccessibles(Personnage bob)
    {
		Collection<Salle> sa = new ArrayList();
		Salle tmp=bob.position();
		Salle ad;
		try
		{
			ad=salles[tmp.getLigne()-1][tmp.getColonne()];
			if(ad != null)
			sa.add(ad); // haut
		}
		catch(Exception e)
		{
		}	
		try
		{
			ad=salles[tmp.getLigne()][tmp.getColonne()+1];
			if(ad != null)
			sa.add(ad); // droite
		}
		catch(Exception e)
		{
		}	
		try
		{
			ad=salles[tmp.getLigne()+1][tmp.getColonne()];
			if(ad != null)
			sa.add(ad); // bas 
		}
		catch(Exception e)
		{
		}	
		try
		{
			ad=salles[tmp.getLigne()][tmp.getColonne()-1];
			if(ad != null)
			sa.add(ad); // gauche
		}
		catch(Exception e)
		{
		}
		return sa;
    }


    public String toString()
    {
		String res="";
		for(int i=0;i<hauteur;i++)
		{
			for(int j=0;j<largeur;j++)
			{
				if(salles[i][j]!=null)
				{
					if(salles[i][j]==entree)
					{
					res+="E";
					}
					else if (salles[i][j]==sortie)
					{
					res+="S";
					}
					else
					{
					res+="_";
					}
				}
				else
				{
					res+="N";
				}
			}
			res+="\n";
		}
		return res;
    }

    public Salle[][] getSalles()
    {
		return salles;
    }
    
    public int getHauteur()
    {
		return hauteur;
    }

    public int getLargeur()
    {
		return largeur;
    }

    public int[] positionEntree()
    {
		int [] ligneColonne = new int [2];
		ligneColonne[0]=entree.getLigne();
		ligneColonne[1]=entree.getColonne();
		return ligneColonne;
    }

    public int[] positionSortie()
    {
		int [] ligneColonne = new int [2];
		ligneColonne[0]=sortie.getLigne();
		ligneColonne[1]=sortie.getColonne();
		return ligneColonne;
    }
}
