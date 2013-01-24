
public class Labyrinthe
{
	private Perso bob;
	private Salle[][] grilleSalle;
	
	public Labyrinthe(int i, int j)
	{
		grilleSalle = new Salle[i][j];
		bob = new Perso();
	}
	
	public void creerLaby()
	{
		int i=0;
		int j=0;
		boolean bon=false;

// initialisation du labyrinthe
		grilleSalle[0][0] = new Salle(0, true, false);
		for (i=0; i<grilleSalle.length; i++)
		{
			for (j=0; j<grilleSalle[i].length; j++)
			{
				grilleSalle[i][j] = new Salle(i*10+j, false, false);
			}
		}
		grilleSalle[grilleSalle.length-1][grilleSalle[0].length-1].setSortie(true);
	
// mettre la position du Perso à la case de départ
		i = j = 0;
		while ( i<grilleSalle.length && j<grilleSalle[0].length || bon == false )
		{
			if ( grilleSalle[i][j].getEntree() == true )
			{
				bob.setPosition(grilleSalle[i][j]);
				bon = true;
			}
			i++;
			j++;
		}
		
// creation des parcours possibles pour le labyrinthe
		Salle[] parcours = new Salle[4];
		parcours[3]=grilleSalle[1][0];
		parcours[2]=grilleSalle[0][1];
		grilleSalle[0][0].setAdj(parcours);
		 
	}
}
