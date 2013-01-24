// LabyrintheApp.java
public class LabyrintheApp{


    public static void afficherSalles(Salle [] s){
	int i=0;
	System.out.println("Salles possibles : ");
	while(i<4 && s[i] != null){
	    System.out.println("Choix  : " + i + " - " + s[i]);
	    i++;
	}
	    
    }
	
    public static void construireLabyrinthe(Labyrinthe l){
	l.setHauteur(5);
	l.setLargeur(5);
	l.setSallesDefaut(5,5);
	Salle salleEntree = new Salle();
	Salle salleSortie = new Salle();
	l.addSalle(salleEntree,0,0);
	l.addSalle(new Salle(),0,2);
    	l.addSalle(new SallePiegee(),0,4);
	l.addSalle(new Salle(),1,0);
	l.addSalle(new Salle(),1,1);
	l.addSalle(new SallePiegee(),1,2);
	l.addSalle(new Salle(),1,3);
	l.addSalle(new Salle(),1,4);
	l.addSalle(new Salle(),2,0);
	l.addSalle(new Salle(),2,2);
	l.addSalle(new SallePiegee(),3,0);
	l.addSalle(new Salle(),3,2);
	l.addSalle(salleSortie,3,4);
	l.addSalle(new SallePiegee(),4,1);
	l.addSalle(new Salle(),4,2);
	l.addSalle(new Salle(),4,3);
	l.addSalle(new Salle(),4,4);
	l.setSalleEntree(salleEntree);
	l.setSalleSortie(salleSortie);
    }
    
    public static void main (String[] args){
	Labyrinthe l = new Labyrinthe();
	construireLabyrinthe(l);
	HerosAvecVie bob = new HerosAvecVie(3,l.getSalleEntree());
	Salle [] sallesVoisines = new Salle [4];
	while(!bob.dead() && !l.estSalleSortie(bob.ouSuisJe()))
	    {
		System.out.println(bob);
		sallesVoisines = l.sallesVoisines(bob.ouSuisJe());
		afficherSalles(sallesVoisines);
		int choix=Lire.lireInt();
		bob.aller(sallesVoisines[choix]);
		if(sallesVoisines[choix] instanceof SallePiegee){
		    ((SallePiegee)sallesVoisines[choix]).boum();
		    bob.perdreUneVie();
		}
	    }
	if(bob.dead())
	    System.out.println("Bob is dead");
	else
	    System.out.println("Bob est sorti !");
    }

}