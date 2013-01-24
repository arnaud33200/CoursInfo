public class Souris extends Animal
{
    public Souris()
    {
	System.out.println("Souris : Constructeur par défaut");
    }
    
    public Souris(int poids)
    {
	super(poids);
	System.out.println("Souris : Constructeur paramétré");
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