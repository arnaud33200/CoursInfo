// Salle.java

// une impl�mentation sans r�f�rence du labyrinthe
// (nous en ferons une seconde avec r�f�rence)

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