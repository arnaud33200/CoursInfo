public class Chat extends Animal
{
    public Chat()
    {
	System.out.println("Chat : Constructeur par défaut");
    }
    
    public Chat(int poids)
    {
	super(poids);
	System.out.println("Chat : Constructeur paramétré");
    }

    public void rigole() // override
    {
	System.out.println("Ma ou");
    }
}