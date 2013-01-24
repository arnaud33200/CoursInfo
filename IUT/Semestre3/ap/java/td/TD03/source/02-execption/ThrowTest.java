public class ThrowTest
{
	public static void main (String argv[])
	{
		int i;

		try { i = Integer.parseInt(argv[0]); }
		catch( ArrayIndexOutOfBoundsException a )
		{
			System.out.println("vous mettre un argument");
			return;
		}
		catch( NumberFormatException n )
		{
			System.out.println("l'argument doit etre un entier");
			return;	
		}
		
		a(i);
	}
	
	public static void c(int i ) throws MyException, MyOtherException
	{
		switch (i)
		{
			case 0 : throw new MyException("i=0 : myexception");
			case 1 : throw new MyOtherException("i=1 : myotherexception");
			case 2 : throw new MySubException("i=2 : mysubexception");
			default : System.out.println("c ok mec ;)");
		}	
		
	}
	
	public static void b(int i) throws MyException
	{
		try { c(i); }
		catch( MyOtherException e )
		{
			System.out.println(e);
			System.out.println(e.getMessage());
			System.out.println("handle at point 2");
		}
	}
	
	public static void a(int i)
	{
		try { b(i); }
		catch ( MyException e )
		{
			if ( e instanceof MySubException )
				System.out.println("sub exception repéré");
			else
				System.out.println("my exception repéte au niveau 1");
		}
	}
	
}
