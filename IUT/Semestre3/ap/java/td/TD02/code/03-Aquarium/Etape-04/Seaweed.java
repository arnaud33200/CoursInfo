public class Seaweed extends AquariumItem{
    String type;
    public Seaweed(Position position,int width,int height,String type){
	super(position,width,height);
	this.type=type;
    }
    public String toString(){
	return "Seaweed" + "\n" +
	    super.toString() + "\n" +
	    "type     : " + type ;
    }
    public void draw(){
	System.out.println("Seaweed  : draw");
    }
}