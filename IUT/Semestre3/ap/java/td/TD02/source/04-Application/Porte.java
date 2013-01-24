// Porte.java
public class Porte extends Lieu 
{
    private boolean estOuverte ;
    private Salle s1;
    private Salle s2;
	
    public Porte(Salle s1,Salle s2){
	estOuverte=false;
	this.s1=s1;
	this.s2=s2;
    }
    
    public boolean estOuverte(){
	return estOuverte;
    }
    
    public void setEstOuverte(boolean ouverture){
	estOuverte=ouverture;
    }
    
    public void entrer(Heros bob)
    {
		
    }
}
