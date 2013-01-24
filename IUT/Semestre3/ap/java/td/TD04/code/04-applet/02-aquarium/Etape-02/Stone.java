import java.awt.*;
import java.util.*;
import java.net.*;

public class Stone extends AquariumItem
{
    private static URL u = ClassLoader.getSystemResource("stone.jpeg"); 
    private static Image stoneImage = Toolkit.getDefaultToolkit().createImage(u);

    public Stone(Point position,int width,int height)
    {
	super(position,width,height,stoneImage);
    }
    /*
    public void draw(Graphics g)
    {
	g.setColor(Color.darkGray);
	g.fillRect(position.x,position.y,width,height);
    }
    */
}