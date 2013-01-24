// Salle.java

// une implémentation sans référence du labyrinthe
// (nous en ferons une seconde avec référence)

public class Salle {
    private int IDSalle ;
    private static int IDCount = 0;

    public Salle(){
	IDSalle=IDCount++;
    }
    
    public String toString(){
	return "Salle id : " + IDSalle;
    }
}