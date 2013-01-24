public class Stone extends AquariumItem{
    String name;
    public Stone(Position position,int width, int height, String name){
	super(position,width,height);
	this.name=name;
    }
    public String toString(){
	return "Stone \n" +
	    super.toString() + "\n" +
	    "name     : " + name ;
    }
    public void draw(){
	System.out.println("Stone    : draw");
    }
}