public class MobileItem extends AquariumItem implements Mobile{
    Position target;
    
    public MobileItem(Position position,int width,int height,Position target){
	super(position,width,height);
	this.target=target;
    }
    public String toString(){
	return super.toString() + "\n" + "target   : " + target ;
    }
    public void draw(){
	System.out.println("MobileItem : draw");
    }
    public Position myTarget(){
	return new Position();
    }
    public void moveTo(){
	if(target.x > position.x) position.x++;
	if(target.x < position.x) position.x--;
	if(target.y > position.y) position.y++;
	if(target.y < position.y) position.y++;
    }
}