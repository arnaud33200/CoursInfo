// FabriqueLabyrintheEnchante.java

public class FabriqueLabyrintheEnchante extends FabriqueLabyrinthe {
    public Salle creerSalle(){
	return new SalleEnchantee();
    }
    public Mur creerMur(){
	return new Mur();
    }
    public Porte creerPorte(Salle s1,Salle s2)
    {
		return new PorteASesame(s1,s2, new Sesame());
    }
}
