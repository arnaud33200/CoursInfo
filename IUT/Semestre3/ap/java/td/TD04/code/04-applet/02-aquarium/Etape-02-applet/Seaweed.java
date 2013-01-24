import java.awt.*;
import java.util.*;
import java.net.*;

public class Seaweed extends AquariumItem
{
    //private static URL u = ClassLoader.getSystemResource("seaweed.jpeg"); 
    //private static Image seaweedImage = Toolkit.getDefaultToolkit().createImage(u);

    public Seaweed(Point position,int width,int height)
    {
	super(position,width,height);
    }

    /*
    public Seaweed(Point position,int width,int height)
    {
	super(position,width,height,seaweedImage);
    }
    */
    public void draw(Graphics g)
    {
	g.setColor(Color.green);
	g.fillRect(position.x,position.y,width,height);
    }
    
}