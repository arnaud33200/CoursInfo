class MyException extends Exception
{
    public MyException()
    {
	super();
    }
    public MyException(String s)
    {
	super(s);
    }
}

class MyOtherException extends Exception
{
    public MyOtherException()
    {
	super();
    }
    public MyOtherException(String s)
    {
	super(s);
    }
}

class MySubException extends MyException
{
    public MySubException()
    {
	super();
    }
    public MySubException(String s)
    {
	super(s);
    }
}

public class ThrowTest {
    public static void main (String argv[])
    {
	int i;

	// contr�le du i saisi
	try{
	    i = Integer.parseInt(argv[0]);
	}
	catch(ArrayIndexOutOfBoundsException e){// argv est vide
	    System.out.println("Vous devez saisir un argument");
	    return;
	}
	catch(NumberFormatException e){// l'argument n'est pas un entier
	    System.out.println("L'argument sp�cifi� doit �tre un entier");
	    return;
	}
	/*
	finally{
	    System.out.println("finally");
	}
	*/
	a(i);
    }

    /*
      la m�thode "a" n'a pas de clause throws
      toutes les exceptions g�n�r�es doivent �tre lev�es
    */
    public static void a (int i)
    {
	try{
	    b(i);
	}
	catch(MyException e){
	    if (e instanceof MySubException)
		System.out.println("MySubException");
	    else
		System.out.println("MyException");
	    //System.out.println(e.getMessage());
	    System.out.println(e);
	    System.out.println("handled at point 1");
	}
    }
    
    /*
      la m�thode "b" progage les exceptions MyException (et sous-classes)
      et l�ve les autres
     */
    public static void b (int i) throws MyException
    {
	try{
	    c(i);
	}
	catch(MyOtherException e){
	    System.out.println("MyOtherException");
	    System.out.println(e.getMessage());
	    System.out.println("handled at point 2");
	}
    }

    public static void c (int i) throws MyException, MyOtherException
    {
	switch(i)
	    {
	    case 0:
		throw new MyException("input 0 -> MyException");
	    case 1:
		throw new MySubException("input 1 -> MySubException");
	    case 2:
		throw new MyOtherException("input 2 -> MyOtherException");
	    default:
		System.out.println("input ok : " + i);
	    }
    }
    
}

