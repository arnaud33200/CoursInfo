import java.util.*;

public abstract class PersonnageLife extends PersonnageDefaut
{
	protected Life vie = new Life(7);		// posséde des vie, gérer par la classe Life
    
    public abstract Salle faitSonChoix(Collection<Salle> sallesAccessibles);
    
    public Salle position()
    {
		return salleCourante;
    }
    
    public void aller(Salle destination)
    {
		salleCourante = destination;

	// detecte si il met le pied dans une salle piégée
	// ainsi on lui retire une vie
		if ( salleCourante instanceof SallePiege )
		{
			vie.perdUneVie();
			System.out.println("Bob a perdu 1 vie, il lui reste " + vie.vieRestant() + " vies restantes");
		}
    }
    
    // méthode pour savoir si notre Personnage peut continuer son parcours
    public boolean estVivant()
    {
		return ( vie.vieRestant() > 0 );
	}
}
