import java.util.*;

public class MyIterator implements Iterator{
	private MyCollection mc;
	private int pos = 0; 
	
	public MyIterator( MyCollection mc ){
		this.mc = mc;
		pos = 0;
	}
	
	public void remove(){
		if (mc.size()>=1){
			mc.tab[mc.last]=null;
			mc.last--;
		}
	}
	
	public Object next(){
		pos++;
		return mc.tab[pos-1];
	}
	
	public boolean hasNext(){
		return (pos<=mc.last);
	}
}
