public class Lion extends Animal
{
    public Lion()
    {
	System.out.println("Lion : Constructeur par d�faut");
    }
    
    public Lion(int poids)
    {
	super(poids);
	System.out.println("Lion : Constructeur param�tr�");
    }

    public void grogne()
    {
	System.out.println("GRRRRAAAa");
    }
}