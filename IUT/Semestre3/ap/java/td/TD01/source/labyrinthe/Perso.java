public class Perso 
{
	private Salle position;		// sa position dans une salle
	private String name;		// nom du perso
	private boolean estSortie;	// indique si il est sortie
	
	public Perso()
	{
		name = "Bob";
		estSortie = false;
	}
	
	public Perso(String name)
	{
		this.name = name;
		estSortie = false;
	}
	
	public boolean getEstSortie() { return estSortie; }
	public String getName() { return name; }
	public Salle getPosition() { return position; }
	
	public void setPosition(Salle pos) { position = pos; }
	public void setEstSortie(boolean s) { estSortie = s; }
}
