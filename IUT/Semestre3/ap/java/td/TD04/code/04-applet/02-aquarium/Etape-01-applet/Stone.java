import java.awt.*;
import java.util.*;

public class Stone extends AquariumItem
{
    public Stone(Point position,int width,int height)
    {
	super(position,width,height);
    }
    public void draw(Graphics g)
    {
	g.setColor(Color.darkGray);
	g.fillRect(position.x,position.y,width,height);
    }
}