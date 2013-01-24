// LabyrintheApp.java
public class LabyrintheApp
{

  public static void afficherSalles (Salle[]s)
  {
    int i = 0;
      System.out.println ("Salles possibles : ");
    while (i < 4 && s[i] != null)
      {
	System.out.println ("Choix  : " + i + " - " + s[i]);
	i++;
      }

  }


  public static void main (String[]args)
  {
		Labyrinthe l = new Labyrinthe ();
		l.construireLabyrinthe ();
		Heros bob = new Heros (l.getSalleEntree ());
		Salle[]sallesVoisines = new Salle[4];
		
		while (!l.estSalleSortie(bob.ouSuisJe()))
		{
			System.out.println (bob);
			sallesVoisines = l.sallesVoisines (bob.ouSuisJe ());
			afficherSalles (sallesVoisines);
			int choix = Lire.lireInt();
			bob.aller (sallesVoisines[choix]);
		}
		System.out.println ("Bob est sorti !");
  }

}
