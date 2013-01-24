import java.applet.Applet;
import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Aquarium extends Applet
{
    private final static int HEIGHT=400;
    private final static int WIDTH =800;
    private final static int NBSTONES  =10;
    private final static int NBSEAWEEDS=10;

    private Collection<AquariumItem> collection;
    private static Random rand=new Random(System.currentTimeMillis());
    
    public void init()
    {
	setSize(WIDTH,HEIGHT);//ou bien setBounds(0,0,WIDTH,HEIGHT);
	collection=new LinkedList<AquariumItem>();
	fill();
    }

    private int randomValue(int min, int max) 
    {
	return rand.nextInt(max-min)+min;
    }	
    
    public void fill()
    {
	Point p;
	Stone s;
	Seaweed r;

	for(int i=0;i<NBSTONES;i++)
	    {
		do{
		    p = new Point(randomValue(0,WIDTH-40),randomValue(0,HEIGHT-40));
		    s = new Stone(p,40,40);
		}while(s.intersects(collection));
		collection.add(s);
	    }

	for(int i=0;i<NBSEAWEEDS;i++)
	    {
		do{
		    p = new Point(randomValue(0,WIDTH-40),randomValue(0+20,HEIGHT-40));
		    r = new Seaweed(p,40,40);
		}while(r.intersects(collection));
		collection.add(r);
	    }
    }

    public void paint(Graphics g)
    {
	super.paint(g);
	for(AquariumItem i : collection)
	    i.draw(g);
    }
}