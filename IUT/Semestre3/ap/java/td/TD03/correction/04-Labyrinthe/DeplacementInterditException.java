// DeplacementInterditException.java

public class DeplacementInterditException extends Exception {
    private Salle origine;
    private Salle destination;
    
    public DeplacementInterditException(Salle origine, Salle destination) {
	this.origine=origine;
	this.destination=destination;
    }
    
    public Salle origine() {
	return origine;
    }
    
    public Salle destination() {
	return destination;
    }
}
