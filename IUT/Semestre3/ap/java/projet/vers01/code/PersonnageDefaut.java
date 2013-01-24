// personnageDefaut.java
// implementation minimaliste de Personnage
// il sera ensuite conseille de deriver cette classe afin
// d'override la methode "faitSonChoix"

import java.util.*;

public abstract class PersonnageDefaut implements Personnage {
    protected Salle salleCourante;
    
    public abstract Salle faitSonChoix(Collection<Salle> sallesAccessibles);
    
    public Salle position()
    {
		return salleCourante;
    }
    
    public void aller(Salle destination)
    {
		salleCourante=destination;
    }
}
