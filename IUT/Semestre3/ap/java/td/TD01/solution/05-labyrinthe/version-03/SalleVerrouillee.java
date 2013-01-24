// SalleVerouillee.java

public class SalleVerrouillee extends Salle{
    private boolean verrouillee;
    private Clef clef;

    public SalleVerrouillee(Clef clef){
	this.clef=clef;
	verrouillee=true;
    }

    public boolean estVerrouillee(){
	return verrouillee;
    }

    public void deverrouiller(Clef c){
	if(c == clef)
	    verrouillee=false;
    }

    public String toString(){
	return super.toString() + (verrouillee?" verrouillee":"");
    }
}