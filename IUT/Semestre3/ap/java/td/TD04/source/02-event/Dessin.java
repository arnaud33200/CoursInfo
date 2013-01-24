import java.awt.*;

public class Dessin extends Canvas
{
	private Color couleur;
	
	public Dessin( Color c )
	{
		super();
		couleur = c;
	}
	
	public void setCouleur( Color c )
	{ couleur = c; }
	
	public void paint( Graphics g)
	{
		super.paint(g);
		g.setColor(couleur);
		g.fillOval(150,50,20,50);
	}
}
