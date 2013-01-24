// Labyrinthe.java
import java.util.*;

public class Labyrinthe {
    private Collection<Salle> salles;
    private Salle salleEntree;
    private Salle salleSortie;

    public Labyrinthe(){
	salles = new LinkedList<Salle>();
    }
    
    public void setSalleEntree(Salle s){
	salleEntree=s;
    }

    public void setSalleSortie(Salle s){
	salleSortie=s;
    }

    public void addSalle(Salle s){
	salles.add(s);
    }
    
    public void creerLabyrinthe(FabriqueLabyrinthe f){
	/*	
        // Avant l'utilisation de la fabrique
		
	Salle s1 = new Salle();
	Salle s2 = new Salle();
	Porte p = new Porte(s1,s2);
	Mur m1 = new Mur();
	Mur m2 = new Mur();
	Mur m3 = new Mur();
	Mur m4 = new Mur();
	Mur m5 = new Mur();
	Mur m6 = new Mur();

	s1.ajouterLieuAdjacent(m1);
	s1.ajouterLieuAdjacent(m2);
	s1.ajouterLieuAdjacent(m3);
	s1.ajouterLieuAdjacent(p);
	s2.ajouterLieuAdjacent(m4);
	s2.ajouterLieuAdjacent(m5);
	s2.ajouterLieuAdjacent(m6);
	s2.ajouterLieuAdjacent(p);

	this.setSalleEntree(s1);
	this.setSalleEntree(s2);
	this.addSalle(s1);
	this.addSalle(s2);
	*/
	
	//	FabriqueLabyrinthe f = new FabriqueLabyrinthe();
	Salle s1 = f.creerSalle();
	Salle s2 = f.creerSalle();
	Porte p = f.creerPorte(s1,s2);
	s1.ajouterLieuAdjacent(f.creerMur());
	s1.ajouterLieuAdjacent(f.creerMur());
	s1.ajouterLieuAdjacent(f.creerMur());
	s1.ajouterLieuAdjacent(p);
	s2.ajouterLieuAdjacent(f.creerMur());
	s2.ajouterLieuAdjacent(f.creerMur());
	s2.ajouterLieuAdjacent(f.creerMur());
	s2.ajouterLieuAdjacent(p);

	this.setSalleEntree(s1);
	this.setSalleEntree(s2);
	this.addSalle(s1);
	this.addSalle(s2);
    }

    public String toString(){
	String res = "";
	for(Salle s : salles)
	    res+= s.toString() + "\n";
	return res;
    }
    
}