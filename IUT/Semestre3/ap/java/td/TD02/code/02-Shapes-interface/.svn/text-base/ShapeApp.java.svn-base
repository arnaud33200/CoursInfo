public class ShapeApp
{
    public static void main(String args[])
    {
	Shape [] s = new Shape [2];
	Drawable [] d = new Drawable [2];

	DrawableCircle    dc = new DrawableCircle(3,10,11);
	DrawableRectangle dr = new DrawableRectangle(5,6,0,1);

	
	s[0] = dc;
	s[1] = dr;
	
	d[0] = dc;
	d[1] = dr;
	
	double area = 0;
	
	for(int i=0;i<s.length;i++)
	    {
		area+=s[i].area();
		d[i].draw();
	    }
	System.out.println("area : " + area );
    }
}