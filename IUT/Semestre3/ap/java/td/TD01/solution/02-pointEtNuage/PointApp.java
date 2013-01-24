import geometrie.* ;

public class PointApp
{
    public static void main (String[] args)
    {
	Point p1 = new Point();
	System.out.println (p1);
	System.out.println ("nombre d'instances : " + Point.nbInstances()); 
	Point p2; // une r�f�rence Point est d�clar�e mais non instanci�e
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	p2=p1;    // p2 r�f�rence le point p1 
	System.out.println ("nombre d'instances : " + Point.nbInstances());
	p1.setX(4);
	p2.setY(5);
	System.out.println (p1);
	System.out.println (p2);
	p2=new Point(p1); // cr�ation d'un point disctint 
                          // �tant une copie de p1
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
