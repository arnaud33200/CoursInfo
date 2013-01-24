import java.awt.*;

public class Droite 
{
    private int xInit;
    private int yInit;
    private int xFin;
    private int yFin;
    private Color couleur;

    public Droite(int xInit,int yInit,int xFin,int yFin,Color couleur)
    {
	this.xInit=xInit;
	this.yInit=yInit;
	this.xFin=xFin;
	this.yFin=yFin;
	this.couleur=couleur;
    }
    
    public void dessine(Graphics g)
    {
	g.setColor(couleur);
	g.drawLine(xInit,yInit,xFin,yFin);
    }
}