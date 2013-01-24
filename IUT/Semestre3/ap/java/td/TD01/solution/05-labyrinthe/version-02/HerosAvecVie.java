// HerosAvecVie.java

public class HerosAvecVie extends Heros {
    private int vie;
    
    public HerosAvecVie(int vie,Salle s){
	super(s);
	this.vie=vie;
    }
    
    public void perdreUneVie(){
	vie--;
    }
    
    public boolean dead(){
	return vie == 0;
    }
    
    public String toString(){
	return super.toString() + "\n" + "vies restantes : " + vie ;
    }
} 