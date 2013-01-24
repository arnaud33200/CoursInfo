public class ShapeApp
{
    public static void main(String args[])
    {
	Shape [] s = new Shape [3];
	s[0]=new Circle(3.0);
	s[1]=new Rectangle(2.0,3.0);
	s[2]=new Rectangle();
	
	((Rectangle)s[2]).setWidth(10);

	double area=0;
	double circumference=0;
	for(int i=0;i<s.length;i++)
	    {
		area+=s[i].area();
		circumference+=s[i].circumference();
	    }
	System.out.println("Area          : " + area + "\n" +
			   "Circumference : " + circumference);
    }
}