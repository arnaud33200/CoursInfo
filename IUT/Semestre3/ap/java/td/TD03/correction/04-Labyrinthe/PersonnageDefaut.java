// PersonnageDefaut.java

public class PersonnageDefaut implements Personnage {
    
    private Salle position = null;
    private Labyrinthe labyrinthe = null ;

    

    public void entrer(Labyrinthe l) {
	labyrinthe = l;
	position = l.entree();
    }
    
    public void aller(Salle s) throws DeplacementInterditException {
	if (!labyrinthe().passage(position, s)) {
	    throw new DeplacementInterditException(position, s);
	}
	position = s;
    }
    
    public Salle position() {
	return position;
    }
    
    
    public Labyrinthe labyrinthe() {
	//	return position.labyrinthe();
	return labyrinthe;
    }
    

    public boolean estSorti() {
	return position.sortie();
    }
    
}
