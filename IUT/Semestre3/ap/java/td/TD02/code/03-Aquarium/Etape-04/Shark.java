public class Shark extends Fish {
    public Shark(Position position,int width,int height,Position target){
	super(position,width,height,target);
    }
    public void draw(){
	System.out.println("Shark    : draw");
    }
}