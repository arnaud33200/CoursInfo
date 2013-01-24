import java.util.*;

public class Aquarium{
    
    public static void remplir (Collection<AquariumItem> collection){
	for(int i=0;i<4;i++){
	    int choix=(int)(Math.random()*4);
	    switch(choix){
	    case 0: collection.add(new Stone(new Position(),2,3,"calcaire"));
		break;
	    case 1: collection.add(new Seaweed(new Position(),1,1,"flottante"));
		break;
	    case 2: collection.add(new Shark(new Position(),5,3,new Position()));
		break;
	    case 3: collection.add(new Sardine(new Position(),2,2,new Position()));
		break;
	    }
	}
    }
    
    public static void afficher(Collection<AquariumItem> collection){
	for(AquariumItem i : collection){
	    System.out.println(i);
	    i.draw();
	    System.out.println();
	}
    }

    public static void bouger(Collection<AquariumItem> collection){
	for(AquariumItem i : collection){
	    if(i instanceof MobileItem)
		((MobileItem)i).moveTo();
	}
    }

    public static void main(String[] args){
	Collection<AquariumItem> collection = new LinkedList<AquariumItem>();
	remplir(collection);
	afficher(collection);
	bouger(collection);
	afficher(collection);
    }
}