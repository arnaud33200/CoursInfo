// LabyrintheDefaut.java

import java.util.*;

public class LabyrintheDefaut implements Labyrinthe {
    private Collection<Salle> salles;
    private Salle entree;

    public LabyrintheDefaut(){
	salles = new LinkedList<Salle>();
    }

    public Collection<Salle> salles(){
	return salles;
    }
    
    public Salle entree(){
	return entree;
    }

    public boolean passage(Salle s1,Salle s2){
	for(Salle s : salles)
	    if(s == s1){
		Collection<Salle> sallesVoisinesS1 = s1.voisines();
		for(Salle v : sallesVoisinesS1)
		    if(v == s2)
			return true;
	    }
	return false;
    }

    public void creerLabyrinthe(){
	SalleDefaut s1 = new SalleDefaut();
	SalleDefaut s2 = new SalleDefaut();
	SalleDefaut s3 = new SalleDefaut();
	SalleDefaut s4 = new SalleDefaut();
	SalleDefaut s5 = new SalleDefaut();
	SalleDefaut s6 = new SalleDefaut();
	SalleDefaut s7 = new SalleDefaut();
	SalleDefaut s8 = new SalleDefaut();
	SalleDefaut s9 = new SalleDefaut();
	SalleDefaut s10 = new SalleDefaut();
	SalleDefaut s11 = new SalleDefaut();

	entree=s1;
	s1.addSalleAdjacente(s2);
	s1.addSalleAdjacente(s6);
	s2.addSalleAdjacente(s1);
	s2.addSalleAdjacente(s3);
	s3.addSalleAdjacente(s2);
	s3.addSalleAdjacente(s4);
	s3.addSalleAdjacente(s5);
	s4.addSalleAdjacente(s3);
	s5.addSalleAdjacente(s3);
	s6.addSalleAdjacente(s1);
	s6.addSalleAdjacente(s7);
	s7.addSalleAdjacente(s6);
	s7.addSalleAdjacente(s8);
	s7.addSalleAdjacente(s10);
	s8.addSalleAdjacente(s7);
	s8.addSalleAdjacente(s9);
	s9.addSalleAdjacente(s8);
	s10.addSalleAdjacente(s7);
	s10.addSalleAdjacente(s11);
	s11.addSalleAdjacente(s10);
	s11.setEstSortie(true);
	
	salles.add(s1);
	salles.add(s2);
	salles.add(s3);
	salles.add(s4);
	salles.add(s5);
	salles.add(s6);
	salles.add(s7);
	salles.add(s8);
	salles.add(s9);
	salles.add(s10);
	salles.add(s11);
    }
}