public class ThrowTest
{
	public static void main (String argv[])
	{
		int i;
		
		try
		{
			i = Integer.parseInt(argv[0]);
		}
		catch( ArrayIndexOutOfBoundsException a )
		{
			System.out.println("bibu");
			return;
		}
		catch( NumberFormatException n )
		{
			System.out.println("abuse");
			return;	
		}
		
		c(i);
	}
	
	public void c(int i )
	{
		try { i == 0; }
		catch( MyException e ) { System.out.println(e);
	}
}
