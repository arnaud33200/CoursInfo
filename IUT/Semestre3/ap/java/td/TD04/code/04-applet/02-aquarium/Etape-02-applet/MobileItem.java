import java.awt.*;
import java.util.*;

public abstract class MobileItem extends AquariumItem implements Mobile
{
    protected Point destination;
    
    public MobileItem(Point position,int width,int height,Point destination)
    {
	super(position,width,height);
	this.destination = destination;
    }
    /*    
    public MobileItem(Point position,int width,int height,Point destination,Image image)
    {
	super(position,width,height,image);
	this.destination = destination;
    }
    */

    public boolean move()
    {
	/// BOF BOF................
	if(this.position.equals(destination)) 
	    {
		return false;
	    }
	int vitesse=(int) (100/(width+height))*3; //Faux,l'idée est là ;)
	if(vitesse<1)
	    vitesse=1;
	int diff_x=Math.abs(destination.x-position.x);
	int diff_y=Math.abs(destination.y-position.y);
	int dx=position.x>destination.x?-1:1;
	int dy=position.y>destination.y?-1:1;
	int newx=position.x+dx*Math.min(vitesse, diff_x);
	int newy=position.y+dy*Math.min(vitesse, diff_y);
	position.x=newx;
	position.y=newy;
	//this.setPosition(new Point(newx,newy));
	// System.out.println(vitesse);
	return true;
	
    }
    
    public Point target(Collection<AquariumItem> neighbors)
    {
	return new Point(Rand.randomValue(0,Aquarium.getAquariumWidth()),
			 Rand.randomValue(0,Aquarium.getAquariumHeight()));
    }
    
    public void setDestination(Point destination)
    {
	this.destination = destination;
    }
}