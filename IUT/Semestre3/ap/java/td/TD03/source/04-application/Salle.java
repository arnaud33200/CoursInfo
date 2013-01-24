public interface Salle
{
    // indique si cette salle est une sortie
    public boolean sortie();
    // salles voisines.
    public Collection<Salle> voisines();
    // informations de la salle
    public String toString();
}
