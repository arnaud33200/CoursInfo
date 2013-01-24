
// Dans cet exercice, on demande de sp�cifier et d'impl�menter une
// version de la classe Pile qui vise � s�curiser et �conomiser la
// place m�moire:
// 1. La fonction empiler devra r�allouer de la place lorsqu'elle en
// aura besoin. Pour ce faire, vous utiliserez la fonction de copie de
// tableau, vue pr�c�demment.
// 2. La fonction d�piler devra r�allouer un nouvel espace, plus petit
// lorsque la pile n'est pas assez remplie.

public class Pile {
   private /*@ spec_public */ int[] zone;
   private /*@ spec_public */ int ptr;
   private /*@ spec_public */ int bloc;

    //@ invariant zone != null;

    //@ requires taille > 0;
    //@ ensures zone != null & ptr == 0 && zone.length == taille;
    public Pile(int taille)
	{
		zone = new int[ taille];
		ptr = 0;
		bloc = 5;
    }

    public void empiler(int elt)
	{
		if ( ptr == zone.length )
		{
			CopieDeTableaux
			int[] tmp = new tmp[zone.length + bloc ];
			
		}
	}

    public int depiler()
	{
	}

    public static void main(String [] a){
	Pile p = new Pile(2);
	Pile p2;
	int x;
	
	p.empiler(5);
	int res = p.depiler();
	//	//@ assert res == ???;   
	p.empiler(x+1);
	
	p.empiler(5);
	p.safeEmpiler(7);
	p.safeEmpiler(9);
	p.depiler();
	p.depiler();
	p.depiler();
	res = p.depiler();
	//	//@ assert res == ???;
	//	//@ assert p.zone.length == ???;
	
    }
}
