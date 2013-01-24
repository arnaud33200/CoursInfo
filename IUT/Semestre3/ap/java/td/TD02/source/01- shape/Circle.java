public class Circle extends Shape
{
    protected double radius;
    protected static final double PI = 3.14159265358979323846;

    public Circle()
    {
		radius=1.0;
    }

    public Circle(double r)
    {
		radius=r;
    }

    public double getRadius()
    {
	return radius;
    }

    public void setRadius(double r)
    {
	radius =r;
    }

    public double area()
    {
	return PI*radius*radius;
    }

    public double circumference()
    {
	return 2*PI*radius;
    }
}
