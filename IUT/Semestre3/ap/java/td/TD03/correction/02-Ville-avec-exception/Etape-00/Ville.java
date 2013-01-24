
/*

  Différence avec Ville-sans-exception :
  Modifications :

  1- ajout de la méthode setNbHabitants
     appelant la méthode erreur en cas d'un passage 
     par paramètre d'un nombre négatif.

  2- appel de la méthode setNbHabitants 
     dans le constructeur :
     public Ville(String nom,int nbHabitants)

 */


public class Ville
{
    private String nom;
    private int nbHabitants;
    
    public Ville(String nom)
    {
	this.nom = nom;
    }
    
    public Ville(String nom,int nbHabitants)
    {
	this(nom);
	//this.nbHabitants = nbHabitants;
	setNbHabitants(nbHabitants);
    }
    
    public final String getNom()
    {
	return nom;
    }
    
    public final boolean nbHabitantsConnu()
    {
	return nbHabitants>0;
    }
    
    public final int getNbHabitants()
    {
	if(nbHabitants <= 0)
	    erreur("nombre inconnu d'habitants");
	return nbHabitants;
    }

    public final void setNbHabitants(int nbHabitants)
    {
	if(nbHabitants <= 0)
	    erreur("nombre d'habitants doit être > 0");
        this.nbHabitants=nbHabitants;
    }
    
    public String toString()
    {
	String description = getClass().getName();
	description += " ( " + nom + " , ";
	if (nbHabitants > 0)
	    description += nbHabitants + " )";
	else
	    description += "? )";
	return description;
    }

    protected void erreur(String message)
    {
	System.out.println("ERREUR : classe : " + getClass().getName() +
			   " : " + message);
	System.exit(1);
    }
}