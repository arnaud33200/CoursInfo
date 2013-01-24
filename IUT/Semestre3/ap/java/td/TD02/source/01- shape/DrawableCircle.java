public class DrawableCircle extends Circle implements Drawable
{
	int color;
	double x, y;
	
	public DrawableCircle()
	{
		color = 1;
		x = y = 5;
	}
	
	public DrawableCircle(int color, double x, double y)
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
		System.out.println("dessin cercle de couleur " + color + " de coordonnée " + x + " - " + y); 
	}
}
