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
        setNbHabitants(nbHabitants);
    }
    
    public final void setNbHabitants(int nbHabitants) throws NbHabException
    {
        if(nbHabitants <= 0)
            throw new NbHabException(nbHabitants);
        this.nbHabitants=nbHabitants;
    }
    
    protected void erreur(String message)
    {
        System.out.println("ERREUR : classe : " + getClass().getName() +
                           " : " + message);
        System.exit(1);
    }
}
