public class Time extends Thread
{
    private Aquarium aquarium;
    
    public Time(Aquarium aquarium) 
    {
	super();
	this.aquarium=aquarium;
    }

    public void run() 
    {
	while(true) 
	    {
		aquarium.go();
		try {
		    //		    Thread.sleep(100);
		    sleep(100);
		} catch (InterruptedException e) {return;}
	    }
    }
}