public class DrawableRectangle extends Rectangle implements Drawable
{
    protected int color;
    protected double abs;
    protected double ord;

    public DrawableRectangle(double h,double w,
			     double abs,double ord)
    {
	super(h,w);
	this.abs=abs;
	this.ord=ord;
    }
    
    public void setColor(int color)
    {
	this.color=color;
    }
    
    public void setPosition(double x,double y)
    {
	abs=x;
	ord=y;
    }
    
    public void draw()
    {
	System.out.println("DrawableRectangle : draw");
    }
}

/*
  implements :

  toutes les méthodes de l'interface doivent
  être implémentées.

  implementer plusieurs interfaces est possible.

 */