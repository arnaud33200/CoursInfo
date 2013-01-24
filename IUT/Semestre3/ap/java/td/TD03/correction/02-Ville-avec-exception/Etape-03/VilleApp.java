public final class VilleApp
{
    public static void main (String args [])
    {
	/*
	Ville v = new Ville("Shanghai",18000000);
	System.out.println(v);
	v.setNbHabitants(-1);
	*/

	try {
	    Ville v = new Ville("Shanghai",-1);
	}
	catch(NbHabException e){
	    System.out.println(e);
	}
	/*
	finally{
	    System.out.println("finally");
	}
	*/
    }
}