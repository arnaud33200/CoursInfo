public class Chat extends Animal
{
    public Chat()
    {
	System.out.println("Chat : Constructeur par d�faut");
    }
    
    public Chat(int poids)
    {
	super(poids);
	System.out.println("Chat : Constructeur param�tr�");
    }

    public void rigole() // override
    {
	System.out.println("Ma ou");
    }
}