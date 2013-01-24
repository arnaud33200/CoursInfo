import java.io.*;
import java.util.*;

/** 
 * cette classe fait une surcharge de "creerLabyrinthe" pour ajouter des salles piégées
**/
public class LabyrinthePiege extends LabyrintheDefaut implements Labyrinthe
{
	protected int nbPieges;
	
	 // cree le labyrinthe
    public void creerLabyrinthe(String file)	
    {
		// A parir d'un fichier !
		Scanner sc=null;
		try { sc = new Scanner(new File(file)); }
		catch(Exception e) { }

	// hauteur largeur
		hauteur=sc.nextInt();
		largeur=sc.nextInt();
		salles = new Salle[hauteur][largeur];

	// coord entree
		int ligneEntree=sc.nextInt();
		int colonneEntree=sc.nextInt();
		entree = new Salle(ligneEntree,colonneEntree);
		
	// coord sortie
		int ligneSortie=sc.nextInt();
		int colonneSortie=sc.nextInt();
		sortie = new Salle(ligneSortie,colonneSortie);

	// on initialise la matrice
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
		
		// le nombre de salles piegees
		int nbPieges = sc.nextInt();
		
		// ajout des nbPieges salles piegees
		for (int i=0; i<nbPieges; i++ )
		{
			int ligne=sc.nextInt();
			int colonne=sc.nextInt();
			salles[ligne][colonne]=new SallePiege(ligne,colonne);	
		}

	// ajout des autres salles
		while(sc.hasNext())
		{
			int ligne = sc.nextInt();
			int colonne = sc.nextInt();
			salles[ligne][colonne] = new Salle(ligne,colonne);
		}
    }
}
