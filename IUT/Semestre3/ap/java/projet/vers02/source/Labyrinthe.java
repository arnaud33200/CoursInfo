// Labyrinthe.java
import java.util.*;

public interface Labyrinthe {
    // cree le labyrinthe
    public void creerLabyrinthe(String file);
    
    // place bob a l'entree du labyrinthe
    public void entrer(Personnage bob);

    // dit si bob est sorti
    public boolean sortir(Personnage bob);

    // renvoie les salles accessibles par bob
    public Collection<Salle> sallesAccessibles(Personnage bob);
}
