// Salle.java

// une impl�mentation sans r�f�rence du labyrinthe

public class Salle {
    private int IDSalle ;
    private static int IDCount = 0;

    public Salle(){
	IDSalle=IDCount++;
    }
    
    public String toString(){
	return "Salle " + IDSalle;
    }
}