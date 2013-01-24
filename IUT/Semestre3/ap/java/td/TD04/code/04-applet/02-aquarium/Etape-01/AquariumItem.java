import java.awt.*;
import java.util.*;

public abstract class AquariumItem 
{
    protected Point position;
    protected int width;
    protected int height;
    //    protected Image image;
    
    public AquariumItem(Point position,int width,int height)
    {
	this.position=position;
	this.width=width;
	this.height=height;
    }

    public Rectangle rectangle()
    {
	return new Rectangle(position, new Dimension(width,height));
    }
    
    public abstract void draw(Graphics g);

    public boolean intersects(Collection<AquariumItem> collection)
    {
	for(AquariumItem i:collection)
	    {
		if(i.rectangle().intersects(this.rectangle()))
		    return true;
	    }
	return false;
    }
}