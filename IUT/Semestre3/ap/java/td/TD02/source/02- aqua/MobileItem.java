public class MobileItem extends AquariumItem implements Mobile
{
	protected Position target;
	
	public MobileItem( Position p, Position t, double h, double w )
	{
		super(p,h,w);
		target = t;
	}
	
	public Position myTarget() { return target; }
	
	public void moveTo(Position t) { target = t; }
	
	public String toString()
	{
		return super.toString() + "\ntarget : " + target;
	}
	
	public void draw()
	{
		System.out.println( "tu me vois, tu me vois plus. normal je move BB" );
	}
}
