import java.awt.*;
import java.net.*;


public class Fish extends MobileItem
{
    private static URL u = ClassLoader.getSystemResource("fish.jpeg"); 
    private static Image fishImage = Toolkit.getDefaultToolkit().createImage(u);
	
    public Fish(Point position,int width,int height,Point destination)
    {
	super(position,width,height,destination,fishImage);
    }
    
    /*
    public void draw(Graphics g)
    {
	g.setColor(Color.red);
	g.fillOval(position.x,position.y,width,height);
    }
    */
}