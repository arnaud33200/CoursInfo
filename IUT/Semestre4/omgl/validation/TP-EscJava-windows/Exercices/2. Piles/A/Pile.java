public class Pile{
    
    // Expliquez le mot-clé 'spec_public'.
    private /*@ spec_public */ int[] zone;
    private /*@ spec_public */ int  ptr;

	

    // A quoi sert la directive 'invariant' ?
    // Reponse: ?

    //@ invariant zone != null;
    //@ invariant ptr >= 0 && ptr <= zone.length;

    //@ requires taille > 0;
    //@ ensures zone != null & ptr == 0 && zone.length == taille;
    public Pile(int taille)
	{
		zone = new int[taille];
    }
    
    // Dans la spécification suivante, expliquez les directives
    // 'modifies' et '\old'. Ecrivez un code conforme à cette
    // spécification.
	
/*   */

    //@ requires ptr < zone.length;
    //@ modifies ptr, zone[ptr-1];
    //@ ensures \old(ptr) + 1 == ptr && zone[\old(ptr)] == elt; 
    public void empiler(int elt)
	{
		zone[ptr] = elt;
		ptr++;
	}
  
    // Précisez la spécification de la fonction suivante, en précisant
    // notamment les valeurs modifiées et la nouvelle valeur de ptr. 

	//@ requires ptr > 0;
	//@ modifies ptr;
    //@ ensures \result==zone[\old(ptr)-1];
    public int depiler()
	{
		ptr--;
		return zone[ptr];
    }     

    // Expliquez le résultat de l'analyse de la fonction suivante:
    public static void main(String[]a)
	{
		Pile p = new Pile(2);
		Pile p2;
		p.empiler(5);
		int res = p.depiler();
		// EXERCICE : Corriger l'assertion:
		//@ assert res == 5;   
		p.empiler(3);
		p.empiler(5);
		p.empiler(7);
    }
}
