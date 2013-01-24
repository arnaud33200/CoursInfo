public class Salle
{
	private int num; 			// numero de la salle
	private boolean entree;		// si c'est la salle d'entrée
	private boolean sortie;		// si c'est la salle de sortie
	private Salle[] adjacents; // indique contient les salles adjacente : G - H - D - B
	
	public Salle( int num, boolean entree, boolean sortie)
	{
		this.num = num;
		this.entree = entree;
		this.sortie = sortie;
/*
		adjacents = new Salle[4];
*/
	}
	
	public int getNum() { return num; }
	public boolean getEntree() { return entree; }
	public boolean getSortie() { return sortie; }
	public Salle[] getAdj() { return adjacents; }
	
	public void setAdj(Salle[] adj) { adjacents = adj; }
	public void setEntree(boolean entree) { this.entree = entree; }
	public void setSortie(boolean sortie) { this.sortie = sortie; }
	
}
