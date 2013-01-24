public class Souris extends Animal
{
    public Souris()
    {
	//super(); // automatique par d�faut
	System.out.println("Souris : Constructeur par d�faut");
    }
    
    public Souris(int poids)
    {
	super(poids);
	System.out.println("Souris : Constructeur param�tr�");
    }
    public void rigole() // override
    {
	System.out.println("Criiii");
    }

    public void grignotte()
    {
	System.out.println("Souris : grignotte");
    }
}