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
	this.nbHabitants = nbHabitants;
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
	System.out.println("classe : " + getClass().getName() +
			   " : " + message);
	System.exit(1);
    }
}