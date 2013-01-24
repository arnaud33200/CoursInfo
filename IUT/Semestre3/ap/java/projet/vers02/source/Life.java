public class Life
{
	private int pointVie;
	
	public Life() { pointVie = 3; }
	public Life( int p ) { pointVie = p; }
	
	public void perdUneVie() 
	{ 
		pointVie--;
	}
	
	public int vieRestant() { return pointVie; }
}
