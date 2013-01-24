// Salle.java
import java.util.*;

public interface Salle {
    // indique si cette salle est une sortie
    public boolean sortie();
    
    // labyrinthe auquel appartient la salle
    //    public Labyrinthe labyrinthe();
    
    // salles voisines.
    public Collection<Salle> voisines();

    public String toString();
}
