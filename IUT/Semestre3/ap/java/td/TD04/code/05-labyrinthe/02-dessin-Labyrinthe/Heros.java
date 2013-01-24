// Heros.java

public class Heros {
    private Salle salleCourante;

    public Heros(Salle s){
	salleCourante=s;
    }
    
    public Salle ouSuisJe(){
	return salleCourante;
    }
    
    public void aller (Salle s){
	salleCourante=s;
    }
    
    public String toString(){
	return "le heros est dans la " + salleCourante.toString();
    }
}