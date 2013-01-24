// SalleAvecClef.java

public class SalleAvecObjet extends Salle {
    private Object objet;

    public SalleAvecObjet(Object objet){
	this.objet=objet;
    }
    
    public Object getObjet(){
	Object o=objet;
	objet=null;
	return o;
    }
}