public class Rectangle extends Shape
{
    protected double height;
    protected double width;

    public Rectangle(double h, double w)
    {
	height=h;
	width=w;
    }
    
    public Rectangle()
    {
	this(1.0,2.0);
    }

    public double getWidth()
    {
	return width;
    }
    
    public double getHeight()
    {
	return height;
    }
    
    public void setWidth(double w)
    {
	width=w;
    }
    
    public void setHeight(double h)
    {
	height=h;
    }

    public double area()
    {
	return height*width;
    }

    public double circumference()
    {
	return 2*(height+width);
    }
}