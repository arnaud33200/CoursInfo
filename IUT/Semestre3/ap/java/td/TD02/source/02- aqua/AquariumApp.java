public class AquariumApp
{
	public static void main(String args[])
	{
		AquariumItem[] aqua = new AquariumItem[4];
		aqua[0] = new Seaweed();
		aqua[1] = new Stone();
		aqua[2] = new Sardine(new Position(5,3), new Position(7,9),2,2);
		aqua[3] = new Shark(new Position(2,3), new Position(5,3),5,4);
		
		for (int i=0; i<3; i++)
		{
			aqua[i].draw();
			System.out.println( aqua[i] );
		}
	}
}
