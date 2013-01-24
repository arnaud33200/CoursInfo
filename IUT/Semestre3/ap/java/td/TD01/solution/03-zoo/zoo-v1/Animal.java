public class Animal
{
    protected int poids;
       
    public Animal(int poids)
    {
	System.out.println("Animal : Constructeur paramétré");
	this.poids=poids;
	
    }
    
    public Animal()
    {
       	//this(0); // appel du constructeur paramétré
	System.out.println("Animal : Constructeur par défaut");

    }
    
    public void rigole()
    {
	System.out.println("Animal : rigole");
    }
}

