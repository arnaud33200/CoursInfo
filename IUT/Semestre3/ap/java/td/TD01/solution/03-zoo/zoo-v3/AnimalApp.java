import java.util.Vector ;

public class AnimalApp
{
    public static Vector construireZoo()
    {
	Vector zoo = new Vector(); 
	for(int i = 0;i<10; i++)
	    {
		int a = (int)(3*Math.random());
		switch(a)
		    {
		    case 0: zoo.add(new Souris(10));
			break;
		    case 1: zoo.add(new Chat(5000));
			break;
		    case 2 : zoo.add(new Lion(100000));
			break;
		    }
	    }
	return zoo;     
    }
    
    public static void chatouillerZoo(Vector zoo)
    {
	for (int i = 0; i < zoo.size(); i++)
	    {
		if (!(zoo.elementAt(i) instanceof Lion)) 
		    ((Animal)(zoo.elementAt(i))).rigole();
		else 
		    ((Lion)(zoo.elementAt(i))).grogne();
	    }
    }
    
    public static void main(String args[])
    {
	chatouillerZoo(construireZoo());
    }
}