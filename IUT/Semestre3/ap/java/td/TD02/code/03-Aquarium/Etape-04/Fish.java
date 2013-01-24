public class Fish extends MobileItem {
    public Fish(Position position,int width,int height,Position target){
	super(position,width,height,target);
    }
    public String toString(){
	return getClass().getName() + "\n" + super.toString();
    }
    public void draw(){
	System.out.println("Fish : draw");
    }
}