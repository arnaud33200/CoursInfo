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
	List<AquariumItem> collection = new ArrayList();
	remplir(collection);
	afficher(collection);
	bouger(collection);
	afficher(collection);
	System.out.println("tri selon la somme de leurs coordonnées ...");
	Collections.sort(  collection, new Comparator(){
		public int compare(Object a, Object b){
			int difference = ((AquariumItem) a).position.x+((AquariumItem) a).position.y - ((AquariumItem) b).position.x - ((AquariumItem) b).position.y;
			if (difference < 0 ) return -1;
			if (difference > 0 ) return 1;
			return 0;
		}
	});
	afficher(collection);
	}
}
