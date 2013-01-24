import java.awt.*;

public class Dessin extends Canvas
{
	public void paint( Graphics g)
	{
		super.paint(g);
		g.setColor(Color.blue);
		g.fillOval(2,2,20,50);
	}
}
