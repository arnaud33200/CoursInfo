import java.utils.Random;

public class AnimalApp
{
	public void creerZoo( Animal[] z )
	{
		Random r = new Random();	
		for ( int i=0; i<5; i++ )
		{
			switch ( r.nextInt(3) )
			{
				case 0 : z[i] = new Animal( i * 45 ); break;
				case 1 : z[i] = new Souris( 5 ); break;
				case 2 : z[i] = new Chat ( i * 6 ); break;
				case 3 : z[i] = new Lion( i * 16 ); break;
			}	
		}
	}
	
	public void carigoledanslezoolool(Animal[] z)
	{
		for ( int i=0; i<z.length; i++ )
		{
			z[i].rigole();
		}
	}
	
	public static void main(String[] args)
	{
		
		Animal zoo[] = new Animal[5];
		for ( int i=0; i<5; i++ )
		{
			if ( i%2 == 0 )
				zoo[i] = new Animal( i * 45 );
			else
			zoo[i] = new Souris( 4 );
				
			zoo[i].rigole();
			try 
			{
				((Souris)zoo[i]).grignotte();
			}
			catch(ClassCastException e)
			{
				System.out.println("c pas une souris :(");
			}
			
		}
	}
}
