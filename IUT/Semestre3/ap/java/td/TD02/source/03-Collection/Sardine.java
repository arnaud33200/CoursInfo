public class Sardine extends Fish
{
	public Sardine( Position p, Position t, double h, double w )
	{
		super(p,t,h,w);
	}
	
	public void draw()
	{
		System.out.println("en boite ou sur pizza, c'est toi qui voit");
	}
}
