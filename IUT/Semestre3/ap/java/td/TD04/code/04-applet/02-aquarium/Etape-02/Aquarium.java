import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Aquarium extends JFrame
{
    private final static int HEIGHT=400;
    private final static int WIDTH =800;
    private final static int NBSTONES  =10;
    private final static int NBSEAWEEDS=10;
    private final static int NBFISHES  =15;

    private Collection<AquariumItem> collection;

    private Graphics gContext;
    private Image buffer;    

    public Aquarium()
    {
	super("Aquarium");
	setSize(WIDTH,HEIGHT);//ou bien setBounds(0,0,WIDTH,HEIGHT);
	setDefaultCloseOperation(DISPOSE_ON_CLOSE); 
	setBackground(Color.white);
	setVisible(true);
	collection=new LinkedList<AquariumItem>();
	fill();
    }

    public void dispose()
    {
	int n = JOptionPane.showConfirmDialog(this,
					      "Quitter ?",
					      "Attention", 
					      JOptionPane.YES_NO_OPTION);
	if(n == JOptionPane.OK_OPTION)
	    super.dispose();
    }
    
    public void fill()
    {
	Point p;
	Stone s;
	Seaweed r;
	Fish f;

	for(int i=0;i<NBSTONES;i++)
	    {
		do{
		    p = new Point(Rand.randomValue(0,WIDTH-40),
				  Rand.randomValue(0,HEIGHT-40));
		    s = new Stone(p,40,40);
		}while(s.intersects(collection));
		collection.add(s);
	    }

	for(int i=0;i<NBSEAWEEDS;i++)
	    {
		do{
		    p = new Point(Rand.randomValue(0,WIDTH-40),
				  Rand.randomValue(0,HEIGHT-40));
		    r = new Seaweed(p,40,40);
		}while(r.intersects(collection));
		collection.add(r);
	    }
	
	for(int i=0;i<NBFISHES;i++)
	    {
       		do{
		    p = new Point(Rand.randomValue(0,WIDTH-40),
				  Rand.randomValue(0,HEIGHT-40));
		    f = new Fish(p,
				 Rand.randomValue(20,60),
				 Rand.randomValue(20,60),p);
		}while(f.intersects(collection));
		collection.add(f);
	    }
    }
    
    public void paint(Graphics g)
    {
	/*
	  super.paint(g);
	  for(AquariumItem i : collection)
	    i.draw(g);
	*/
	if (gContext == null)
	    {
		buffer = createImage (WIDTH,HEIGHT);
		gContext = buffer.getGraphics ();
	    }
	gContext.setColor(Color.white);
	gContext.fillRect(0,0,WIDTH,HEIGHT);
	for(AquariumItem i : collection) 
	    {
		i.draw(gContext);
	    }
	g.drawImage(buffer,0,0,null);
    }
    
    public static int getAquariumWidth()
    {
	return WIDTH;
    }

    public static int getAquariumHeight()
    {
	return HEIGHT;
    }
    
    public void go()
    {
	for(AquariumItem i:collection) 
	    {
		if(i instanceof Mobile) 
		    {
			Mobile m=(Mobile) i;
			boolean hasMoved = m.move();
			if(!hasMoved)
			    ((MobileItem)m).setDestination(m.target(null));
		    }
	    }
	this.repaint();
    }
    
}