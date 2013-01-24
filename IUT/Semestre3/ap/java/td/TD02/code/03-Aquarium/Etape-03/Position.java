public class Position{
    public int x;
    public int y;
    
    public Position(){
	this((int)(Math.random()*10),(int)(Math.random()*10));
    }
    public Position(int x,int y){
	this.x=x;
	this.y=y;
    }
    
    public String toString(){
	return "(" + x + "," + y + ")";
    }
  
}