public class AnimalApp
{
    public static Animal[] construireZoo()
    {
	Animal zoo[] = new Animal[10]; 
	for(int i = 0;i<zoo.length; i++)
	    {
		int a = (int)(3*Math.random());
		switch(a){
		case 0: zoo[i] = new Souris(1);
		    break;
		case 1: zoo[i]=new Chat(5);
		    break;
		case 2 : zoo[i] = new Lion(100);
		    break;
		}
	    }
	return zoo;       
    }
    
    public static void chatouillerZoo(Animal zoo[])
    {
	for (int i = 0; i < zoo.length; i++)
	    {
		if (!(zoo[i] instanceof Lion)) 
		    zoo[i].rigole();
		else 
		    ((Lion)zoo[i]).grogne();
	    }
    }
    
    public static void main(String args[])
    {
	chatouillerZoo(construireZoo());
    }
}