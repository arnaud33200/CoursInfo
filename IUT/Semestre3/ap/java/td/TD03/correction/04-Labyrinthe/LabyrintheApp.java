// LabyrintheApp.jave

import java.util.*;

public class LabyrintheApp {
    public static void main(String[] args){
	Labyrinthe labyrinthe = new LabyrintheDefaut();
	((LabyrintheDefaut)labyrinthe).creerLabyrinthe();
	Personnage bob = new PersonnageDefaut();
	bob.entrer(labyrinthe);
	
	while(!bob.estSorti())
	    {
		Salle positionCourante = bob.position();
		System.out.println("-------------------------------------");
		System.out.println("Salle courante : " + positionCourante);
		Collection<Salle> sallesVoisines = positionCourante.voisines();
		System.out.println("Où voulez-vous aller ?");
		int i=0;
		for(Salle s : sallesVoisines){
		    System.out.println("Choix " + i + " : " + s);
		    i++;
		}
		System.out.println("Entrer votre choix");
		int choix = Lire.lireInt();
		try{
		    bob.aller((Salle)((LinkedList)sallesVoisines).get(choix));
		}
		catch(DeplacementInterditException e){
		    System.out.println("probleme...");
		    System.exit(1);
		}
	    }
	System.out.println("Bob est sorti");
    }
    
}