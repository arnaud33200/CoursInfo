import java.awt.*;
import javax.swing.*;

public class Carres extends JApplet 
{
    public void paint(Graphics g)
    {
	int w = this.getWidth()-20;
	int[] xP;
	xP=new int[4];
	xP[0]=10;
	xP[1]=w;
	xP[2]=w;
	xP[3]=10;
	int[] yP;
	yP=new int[4];
	yP[0]=10;
	yP[1]=10;
	yP[2]=w;
	yP[3]=w;
	int nbP=4;
	boolean cool=true;
	g.setColor(Color.lightGray);
	g.fillPolygon(xP, yP, nbP);	   
	for (int i=1; i<=9; i++)
	    {
		if(cool) g.setColor(Color.white);
		else  g.setColor(Color.lightGray);
		
		int x0=xP[0];
		xP[0]=(xP[0]+xP[1])/2;
		xP[1]=(xP[1]+xP[2])/2;
		xP[2]=(xP[2]+xP[3])/2;
		xP[3]=(xP[3]+x0)/2;
		int y0=yP[0];
		yP[0]=(yP[0]+yP[1])/2;
		yP[1]=(yP[1]+yP[2])/2;
		yP[2]=(yP[2]+yP[3])/2;
		yP[3]=(yP[3]+y0)/2;
		
		g.fillPolygon(xP, yP, nbP);
		cool=!cool;
	    }
    }
}