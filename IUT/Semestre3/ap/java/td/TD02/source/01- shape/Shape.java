	public abstract class Shape
	{
		public abstract double area();
		public abstract double circumference();
	}

/*
  Toute classe contenant une m�thode abstraite est abstraite et
  doit �tre d�clar�e comme tel.
  
  Une classe peut �tre d�finie comme abstraite sans contenir de 
  m�thodes abstraites (emp�che l'instanciation).

  Une classe abstrainte ne peut pas �tre instanci�e.

  Une sous-classe peut �tre instanci�e si et seulement si elle implemente
  toutes les methodes abstraites de sa classe m�re (abstraite).

  Une sous-classe qui n'instancie qu'en partie les methodes abstraites
  de sa classe m�re (abstraite) est abstraite.
  
 */
