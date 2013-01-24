package geometrie ;

public class Nuage
{
    private final static int MAX = 100;
    private Point[] tab;
    private int nbPoints ;

    public Nuage()
    {
    	tab = new Point[MAX];
	nbPoints = 0;
    }
    
    public void addPoint(Point p)
    {
	tab[nbPoints]=p;
	nbPoints++;
    }

    private Point pointSUDOUEST()
    {
	Point res = new Point(tab[0]);
	for(int i=0;i<nbPoints;i++)
	    {
		if(res.getX() > tab[i].getX())
		    res.setX(tab[i].getX());
		if(res.getY() > tab[i].getY())
		    res.setY(tab[i].getY());
	    }
	return res;
    }

    private Point pointNORDEST()
    {
	Point res = new Point(tab[0]);
	for(int i=0;i<nbPoints;i++)
	    {
		if(res.getX() < tab[i].getX())
		    res.setX(tab[i].getX());
		if(res.getY() < tab[i].getY())
		    res.setY(tab[i].getY());
	    }
	return res;
    }

    public Point[] boite()
    {
	Point SO = pointSUDOUEST();
	Point NE = pointNORDEST();
      	Point [] res = new Point[2];
	res[0] = SO;
	res[1] = NE;
	return res;
    }

    public String toString()
    {
	String res = "";
	for(int i=0;i<nbPoints;i++)
	    res+=tab[i] + "\n";
	return res;
    }
    
}