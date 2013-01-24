public abstract class AquariumItem
{
	protected Position pos;
	protected double width, height;
	
	public AquariumItem()
	{
		pos = new Position(0,0);
		width = height = 5;
	}
	
	public AquariumItem( Position p, double h, double w)
	{
		pos = p;
		width = w;
		height = h;
	}
	
	public String toString()
	{
		return pos + "\nlargeur : " + width + " hauteur : " + height + "\n";
	}
	
	public abstract void draw();


	
	
}
