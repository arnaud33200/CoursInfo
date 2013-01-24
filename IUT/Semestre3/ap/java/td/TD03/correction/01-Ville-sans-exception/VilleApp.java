public final class VilleApp
{
    public static void main (String args [])
    {
	Ville v [] = new Ville [4];

	v[0] = new Ville("Barcelone");
	v[1] = new Ville("Shanghai", 18000000);
	v[2] = new Capitale("Oulan-Bator",1000000,"Mongolie");
	v[3] = new Capitale("Beijing");

	for(int i=0;i<v.length;i++)
		System.out.println(v[i]);
	
	//int n = v[0].getNbHabitants();
	//int n = v[3].getNbHabitants();
	//System.out.println("nbHabitant : " + n);

	System.out.println(((Capitale)v[2]).getPays());
    }
}