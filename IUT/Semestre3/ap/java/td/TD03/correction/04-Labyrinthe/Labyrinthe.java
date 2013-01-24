// Labyrinthe.java

import java.util.*;

public interface Labyrinthe {
    // salles composant le labyrinthe
    public Collection<Salle> salles();
    
    // renvoie la salle d'entree
    public Salle entree();
    
    // renvoie vrai ssi il existe un passage de s1 à s2
    public boolean passage(Salle s1, Salle s2);
}
