import java.util.*

public class MyIterator implements Iterator
{
	private MyCollection collect;
	private int pos = 0;
	
	public MyIterator( MyCollection c )
	{
		collect = c;
	}
	
	public boolean hasNext()
	{
		return ( pos <= collect.indice );
	}
	
	public Object next()
	{
		pos++;
		return obj[pos-1];
	}
	
	public void remove()
	{
		collect.indice--;
		pos--;
	}
}
