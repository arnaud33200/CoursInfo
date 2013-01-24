import java.util.*;

public class MyCollection extends AbstractCollection implements Collection{
	private int MAX = 1000;
	public Object[] tab = new Object[MAX];
	public int last = -1;
	
	// methodes essentielles de Colection
	public boolean add( Object o ){
		if (last>=MAX-1) return false;
		last++;
		tab[last]=o;
		return true;
	}
	
	public int size(){
		return (last+1);
	}
	
	public Iterator iterator(){
		return new MyIterator( this );
	}
}

