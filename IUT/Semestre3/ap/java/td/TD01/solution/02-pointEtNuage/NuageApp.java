import geometrie.* ;

public class NuageApp
{
    public static void main (String[] args)
    {
		int nb;
		Nuage n = new Nuage();

		System.out.println("Nombre de points du nuage ?");
		nb=Lire.lireInt();

		for(int i=0;i<nb;i++)
	    n.addPoint(new Point(Lire.lireDouble(),Lire.lireDouble()));

		System.out.println(n);
	
		Point [] res;
		res=n.boite();
		System.out.println(res[0] + " " + res[1]);
    }
} 
