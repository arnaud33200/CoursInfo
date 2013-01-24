
/*

  Différence avec Ville-sans-exception :
  Modifications :

  1- ajout de la méthode setNbHabitants
     appelant la méthode erreur en cas d'un passage 
     par paramètre d'un nombre négatif.

  2- appel de la méthode setNbHabitants 
     dans le constructeur :
     public Ville(String nom,int nbHabitants)

  Etape-01
  
  3- ajout de la classe NbHabException

  4- la méthode setHabitants génère une exception 
     sans la traiter.

  La compilation donne une erreur :
  une exception est générée mais n'est pas levée.
  -> exception dite contrôlée ou checked
  doit absolument être propagée ou levée.

  Etape-02

  5- ajout de la clause throws dans le constructeur
     l'exception est propagée.

  Toujours des erreurs lors de la compilation :
  l'exception est bien propagée jusqu'à VilleApp
  mais n'est pas levée.

  Etape-03

  6- l'exception est levée dans VilleApp

 */


public class Ville
{
    private String nom;
    private int nbHabitants;
    
    public Ville(String nom)
    {
	this.nom = nom;
    }
    
    public Ville(String nom,int nbHabitants) throws NbHabException
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

    public final void setNbHabitants (int nbHabitants) throws NbHabException
    {
	if(nbHabitants <= 0)
	    throw new NbHabException(nbHabitants);
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