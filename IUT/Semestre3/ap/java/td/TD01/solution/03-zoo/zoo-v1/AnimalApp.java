public class AnimalApp
{
    public static void main(String args[])
        {
	    System.out.println("------ Constructeurs");

    	    Animal z1 = new Animal();
	    /*
	    z1.rigole();
	    Animal z2 = new Animal(5);
	    z2.rigole();
	    */
	    Souris z3 = new Souris();
	    /*
	    z3.rigole();
	    z3.grignotte();
	    Souris z4 = new Souris(1);
	    z4.rigole();
	    z4.grignotte();
	    */
	    
	    System.out.println("------ Reconnaissance du type");
	    
	    Animal [] a = new Animal[2];
	    a[0]=z1;
	    a[1]=z3;


	    for(int i=0;i<a.length;i++)
		a[i].rigole();
	    // reconnaissance du type réel

	    System.out.println("------ Transtypage");

	    Object o = z3;
	    ((Souris)o).grignotte();
	    // si non cast, erreur lors de la compilation
	    // en effet Object ne contient pas de méthode grignotte

	    Animal z5 = z3;
	    ((Souris)z5).grignotte();
	    // si non cast, erreur lors de la compilation
	    // en effet Animal ne contient pas de méthode grignotte

	    z5.rigole();
	    // Animal contient une méthode rigole
	    // Aucune erreur lors de la compilation
	    // reconnaissance dynamique du type
            // Criiiiii

	    ((Animal)z5).rigole();
	    // Animal contient une méthode rigole
	    // Aucune erreur lors de la compilation
	    // reconnaissance dynamique du type
            // Criiiiii

	    // comment faire un appel de rigole de la classe mère ?
	    //((Animal)z5).Animal.rigole();

	    Animal z6 = new Animal();
	    // Souris z7 = z6 ; // Invalide
	    // Souris z7 = (Souris) z6; // Compilation OK, Execution erreur

	    Animal z7 = new Souris();
	    //z6 = z7;	    
	    Souris z8 = (Souris) z7;
	    z8.rigole();

	    // pas besoin de transtypage pour monter dans la hiérarchie
	    // Transtypage obligatoire pour redescendre dans la hiérachie
	    // Échec du transtypage 
	    // si l'objet n'a pas été instancié de façon au moins aussi spécialisé.


	    
	}
}