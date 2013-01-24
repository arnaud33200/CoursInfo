// Salle.java
import java.util.*;

public class Salle extends Lieu {
    private static int compteurSalle=0;
    protected int numSalle ;
    private Collection<Lieu> lieuxAdjacents;

    public Salle(){
	numSalle=compteurSalle++;
	lieuxAdjacents=new LinkedList<Lieu>();
    }
    
    public void ajouterLieuAdjacent(Lieu l){
	lieuxAdjacents.add(l);
    }
    
    public Collection<Lieu> getLieuxAdjacents(){
	return lieuxAdjacents;
    }

    public void entrer(Heros bob){

    }

    public String toString(){
	String res = "Salle (normale) num " + numSalle;
	return res;
    }
}