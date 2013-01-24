// Personnage.java
import java.util.*;

public interface Personnage {
    // renvoie une salle parmi sallesAccesibles
    public Salle faitSonChoix(Collection<Salle> sallesAccessibles);

    // renvoie sa position courante
    public Salle position();
    
    // deplace Bob de sa position courante vers sa destination
    public void aller(Salle destination);
}
