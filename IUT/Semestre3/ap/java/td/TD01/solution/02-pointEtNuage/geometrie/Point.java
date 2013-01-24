package geometrie ;

public class Point
{
    private double x;
    private double y;
    private int id;
    private static final double EPSILON = 0.000001;
    private static int nbPoints = 0; 
    
    public Point ()
    {
	System.out.println("Constructeur par défaut");
	id=++nbPoints;
    }
    
    public Point (double x, double y)
    {
	System.out.println("Constructeur paramétré (abs,ord)");
	this.x=x;
	this.y=y;
	id=++nbPoints;
    }

    public Point (Point p)
    {
	System.out.println("Constructeur paramétré (Point)");
	x=p.x;
	y=p.y;
	id=++nbPoints;
    }
    
    public void setX(double x)
    {
	this.x=x;
    }

    public void setY(double y)
    {
	this.y=y;
    }
    
    public double getX()
    {
	return x;
    }
    
    public double getY()
    {
	return y;
    }
    
    public void move(double dx,double dy)
    {
	x+=dx;
	y+=dy;
    }

    public static int nbInstances()
    {
	return nbPoints;
    }

    public String toString()
    {
	return "(" + id + " , [" + x + " , " + y + "] )";
    }
}