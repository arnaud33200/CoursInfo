// SallePiegee.java

public class SallePiegee extends Salle {
    private boolean piege ;
    
    public SallePiegee(){
	piege=true;
    } 

    public void boum(){
	piege=false;
    }
    
    public String toString(){
	return super.toString() + (piege?" avec piege":"");
    }
}