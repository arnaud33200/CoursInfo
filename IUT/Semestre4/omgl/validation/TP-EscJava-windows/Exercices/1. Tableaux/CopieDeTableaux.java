public class CopieDeTableaux {

    public CopieDeTableaux() {}


    // Question: Expliquez les directives 'requires' et 'ensures'
    // utilisée ci-dessous:

    // Reponse: ?

    
    // Trouvez la bonne valeur pour les ??? (une fois remplacée,
    // retirez les premiers commentaires de la seconde ligne).
    //@ requires t != null
    //@ ensures (\forall int j; j>=0 & j < t.length ==> t[j] == x);
    public static void affecter(int[] t, int x){
	int i = 0;
	
	// Question: Expliquez la directive 'loop_invariant'
	// utilisée ci-dessous.
	// Reponse: hypothése de récurence
	// elle doit etre vrai à tout les tours

	// Question: Complétez la seconde directive (remplacez les '???'
	// par l'expression correcte)
	// Reponse: ?

	//@ loop_invariant i>=0;
	//@ loop_invariant (\forall int j; j>=0 & j < i ==> t[j] == x);
	while( i < t.length)
	{
	    t[i] = x;
	    i++;
	}
    }


    // Exercice: En vous inspirant de l'exemple ci-dessus. Rédigez la
    // spécification formelle (directives 'ensures' et 'requires') de
    // la fonction 'copie' dont le prototype est donné et codez-là de
    // façon conforme à cette spécification. (esc/java doit le
    // vérifier!). Attention, les assertions de la fonction 'test'
    // ci-dessous doivent également être vérifiez

	//@ requires t1 != null && t2 != null
	//@ requires t1.length <= t2.length
	//@ ensures (\forall int j; j>=0 && j < t1.length ==> t1[j] == t2[j])
    public static void copie(int[] t1, int[] t2)
	{ 
		//@ loop_invariant i>=0
		//@ loop_invariant (\forall int j; j>=0 && j < i ==> t1[j] == t2[j])
		for( int i=0; i<t1.length; i++ )
		{
			t2[i] = t1[i];
		}
	}

    public void test()
	{
		int[] t1  = {1,9,11,15,56,78,89};
	//@ assert t1[5] == 78;
		int[] t2 = new int[t1.length];
		copie(t1,t2);
	//@ assert t2[5] == 78;
    }
}
