import java.awt.*;
import javax.swing.*;

public class Damier extends JApplet 
{
    private static final int NC=10;

    public void paint(Graphics g)
    {
	
	int l, c, d ;
	l = c = d = this.getWidth()/NC;
	boolean cool=false;
	for(int j=0;j<NC;j++)
	    {
		cool=!cool;
		for(int i=0;i<NC;i++){
		    if(cool) 
			g.setColor(Color.white);
		    else  
			g.setColor(Color.black);
		    g.fillRect(i*c,j*l,d,d);
		    cool=!cool;
		}
	    }
    }
}