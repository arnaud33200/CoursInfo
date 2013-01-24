import java.awt.*;

public class GrilleJeton extends Canvas
{
	private Point coordonnee;
	private Point grilleSize;
	private Jeton grille;
	
	public GrilleJeton( string t, Point p, Point g)
	{
		super(t);
		coordonnee = p;
		grilleSize = g;
		grille = new Jeton[5][5];
	}
}
