import java.awt.*;
import java.util.*;

public class Seaweed extends AquariumItem
{
    public Seaweed(Point position,int width,int height)
    {
	super(position,width,height);
    }
    public void draw(Graphics g)
    {
	g.setColor(Color.green);
	g.fillRect(position.x,position.y,width,height);
    }
}