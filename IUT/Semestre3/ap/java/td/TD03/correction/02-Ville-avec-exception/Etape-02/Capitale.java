public class Capitale extends Ville
{
    private String pays;
    
    public Capitale(String nom)
    {
	super(nom);
    }
    
    public Capitale(String nom,int nbHabitants) throws NbHabException
    {
	super(nom,nbHabitants);
    }

    public Capitale(String nom,int nbHabitants,String pays) throws NbHabException
    {
	super(nom,nbHabitants);
	this.pays=pays;
    }
    
    public String getPays()
    {
	return pays;
    }
    
    public String toString()
    {
	String description = super.toString() + " du pays "; 
	if(pays == null)
	    description += "inconnu";
	else
	    description += pays;
	return description;
    }
}