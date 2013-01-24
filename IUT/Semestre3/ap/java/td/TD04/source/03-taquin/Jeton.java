import java.awt.*;

public class Jeton extends Point
{
	private int numero;
	private Color couleur;
	
	public Jeton(int n, Color c)
	{
		numero = n;
		couleur = c;
	}
	
	public int getNumero(){ return numero; }
	public Color getCouleur(){ return couleur; }
	
	public void setCouleur(Color c){ couleur = c; }
	
}
