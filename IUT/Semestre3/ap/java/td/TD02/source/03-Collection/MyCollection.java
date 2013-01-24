import java.util.*;

public class MyCollection extends AbstractCollection implements Collection
{
	private int MAX = 100;
	public Object[] obj = new Object[MAX];
	public int indice = -1;

	public boolean add( Object o )
	{
		if( indice+1 >= 100 )
		{
			System.out.println("collection pleine !");
			return false;
		}
		else
		{
			indice++;
			obj[indice] = 0;
			return true;
		}
	}
	
	public int size() { return indice+1; }
	
	public Iterator iterator()
	{
		return new MyIterator( this );
	}
}
