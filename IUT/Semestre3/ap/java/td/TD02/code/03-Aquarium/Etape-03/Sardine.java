public class Sardine extends Fish {
    public Sardine(Position position,int width,int height,Position target){
	super(position,width,height,target);
    }
    public void draw(){
	System.out.println("Sardine  : draw");
    }
}