	public abstract class Shape
	{
		public abstract double area();
		public abstract double circumference();
	}

/*
  Toute classe contenant une méthode abstraite est abstraite et
  doit être déclarée comme tel.
  
  Une classe peut être définie comme abstraite sans contenir de 
  méthodes abstraites (empèche l'instanciation).

  Une classe abstrainte ne peut pas être instanciée.

  Une sous-classe peut être instanciée si et seulement si elle implemente
  toutes les methodes abstraites de sa classe mère (abstraite).

  Une sous-classe qui n'instancie qu'en partie les methodes abstraites
  de sa classe mère (abstraite) est abstraite.
  
 */
