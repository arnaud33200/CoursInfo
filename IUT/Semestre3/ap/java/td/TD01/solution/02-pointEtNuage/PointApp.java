import geometrie.* ;

public class PointApp
{
    public static void main (String[] args)
    {
	Point p1 = new Point();
	System.out.println (p1);
	System.out.println ("nombre d'instances : " + Point.nbInstances()); 
	Point p2; // une référence Point est déclarée mais non instanciée
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	p2=p1;    // p2 référence le point p1 
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	p1.setX(4);
	p2.setY(5);
	System.out.println (p1);
	System.out.println (p2);
	p2=new Point(p1); // création d'un point disctint 
                          // étant une copie de p1
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	p2.setX(1);
	p2.setY(2);
	System.out.println (p1);
	System.out.println (p2);
	Point p3 = new Point (p1.getX(),p2.getY());
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	System.out.println (p3);
    }
} 
