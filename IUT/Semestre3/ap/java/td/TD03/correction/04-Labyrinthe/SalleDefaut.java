// SalleDefaut.java

import java.util.*;

public class SalleDefaut implements Salle {
    private static int cpt = 0;
    private int id;
    private boolean estSortie;
    private Collection<Salle> sallesAdjacentes;
    
    public SalleDefaut(){
	id=cpt++;
	estSortie=false;
	sallesAdjacentes = new LinkedList<Salle>();
    }
    
    public void addSalleAdjacente(Salle s){
	sallesAdjacentes.add(s);
    }

    public void setEstSortie(boolean s){
	estSortie=s;
    }
    
    public boolean sortie(){
	return estSortie;
    }

    public Collection<Salle> voisines(){
	return sallesAdjacentes;
    }

    public String toString(){
	return "salle id " + id ;
    }
}