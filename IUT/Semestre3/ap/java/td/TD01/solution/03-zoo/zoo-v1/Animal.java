public class Animal
{
    protected int poids;
       
    public Animal(int poids)
    {
	System.out.println("Animal : Constructeur param�tr�");
	this.poids=poids;
	
    }
    
    public Animal()
    {
       	//this(0); // appel du constructeur param�tr�
	System.out.println("Animal : Constructeur par d�faut");

    }
    
    public void rigole()
    {
	System.out.println("Animal : rigole");
    }
}

