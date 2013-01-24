public class Start
{
    public static void main (String args[])
    {
	Aquarium aquarium = new Aquarium();
	Time timer = new Time(aquarium);
	timer.start();
    }
}