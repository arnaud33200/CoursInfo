// LabyrintheApp.java

public class LabyrintheApp 
{
    
    public static void main (String[] args)
    {
		Labyrinthe l = new Labyrinthe();
		FabriqueLabyrinthe f = new FabriqueLabyrintheEnchante();
		l.creerLabyrinthe(f);
		System.out.println(l);
   	} 
}
