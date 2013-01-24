public class Lion extends Animal
{
    public Lion()
    {
	System.out.println("Lion : Constructeur par défaut");
    }
    
    public Lion(int poids)
    {
	super(poids);
	System.out.println("Lion : Constructeur paramétré");
    }

    public void grogne()
    {
	System.out.println("GRRRRAAAa");
    }
}