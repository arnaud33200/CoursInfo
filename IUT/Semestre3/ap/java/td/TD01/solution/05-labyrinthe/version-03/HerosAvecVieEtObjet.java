// HerosAvecVieEtObjet.java

public class HerosAvecVieEtObjet extends HerosAvecVie {
    private Object objet;
    
    public HerosAvecVieEtObjet(int vie,Salle s){
	super(vie,s);
	objet=null;
    }
    
    public void prendreObjet(Object objet){
	this.objet=objet;
    }

    public boolean aUnObjet(){
	return objet!=null;
    }

    public Object utiliserObjet(){
	Object o=objet;
	objet=null;
	return o;
    }

    public String toString(){
	return super.toString() + (objet != null? "\n" + "avec objet" : "");
    }
} 