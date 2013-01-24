public class DrawableRectangle extends Rectangle implements Drawable
{
	int color;
	double x, y;
	
	public DrawableRectangle()
	{
		color = 1;
		x = y = 5;
	}
	
	public DrawableRectangle(int color, double x, double y)
	{
		this.color = color;
		this.x = x;
		this.y = y;
	}
	
	public void setColor( int color)
	{
		this.color = color;
	}
	
	public void setPosition(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	
	public void draw()
	{
		System.out.println("dessin rectangle de couleur " + color + " de coordonnée " + x + " - " + y); 
	}
}
