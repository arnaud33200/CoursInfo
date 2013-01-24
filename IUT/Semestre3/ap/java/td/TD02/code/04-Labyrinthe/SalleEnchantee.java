// SalleEnchantee.java

public class SalleEnchantee extends Salle{
    private Object o;
    
    public SalleEnchantee()
    {
		o=null;
    }
    
    public void addObject(Object o)
    {
		this.o=o;
    }
    
    public Object getObject()
    {
		return o;
    }

    public void removeObject(){
	o=null;
    }

    public String toString(){
	String res = "SalleASesame num " + numSalle;
	return res;
    }
}
