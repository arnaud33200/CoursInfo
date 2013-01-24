// Personnage.java

public interface Personnage {
    // positionne un personnage dans la salle d'entree d'un labyrinthe.
    public void entrer(Labyrinthe l);

    // labyrinthe ou se trouve le personnage.
    public Labyrinthe labyrinthe();
    
    // salle ou se trouve le personnage.
    public Salle position();

    // deplace le personnage si il existe un passage entre sa position
    // et la nouvelle salle.
    public void aller(Salle s) throws DeplacementInterditException;

    // vrai si et seulement si la position du personnage est une sortie.
    public boolean estSorti();
}
