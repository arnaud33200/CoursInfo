public class Position
{
	private double x, y;
	
	public Position()
	{
		x = y =0;
	}
	
	public Position( double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	
	public String toString()
	{
		return "position : " + x + " - " + y + "\n";
	}
	
	public double getX() { return x; }
	public double getY() { return y; }
	
	public void setX( double x ) { this.x = x; }
	public void setY( double y ) { this.y = y; }
	
}
