	// MyPersonnage.java

import java.util.*;

public class MyPersonnage extends PersonnageDefaut 
{
	private Collection<Salle> passed = new ArrayList();				// toutes les salles deja traversées.
	private Collection<Salle> allowed = new ArrayList();			// toutes les salles autorisées.
	private Collection<Salle> forbid = new ArrayList();				// toutes les salles interditent.


    public Salle faitSonChoix(Collection<Salle> sallesAccessibles)
    {
		boolean salleNotPassed;								
		Salle reponse = salleCourante;						// salle selectionnée
		allowed = salleAllowed(sallesAccessibles);			// on ne garde que les salles non interdites
		
// traite selon le nombre de salles autorisées 
		switch(allowed.size())								
		{
	// cas d'un cul de sac
	// on est obligé de faire demi tour donc c'est un chemin interdit
			case 1:											
			{												
				reponse = (Salle)(allowed.toArray())[0];	
				forbid.add(salleCourante);					// ajout du cul de sac a la liste des salles interdites
				break;											
			}
	// cas ou il y a entre deux et quatres choix
			default:										
			{
				salleNotPassed = false;						
				int i = 0;									
				if( passed.size() > 0)							
				{
			// il cherche la premiere salle inconnue
			// pour la determiné comme chemin a prendre
			// et la marquer comme "passée"
					while(!salleNotPassed && i < allowed.size() ) 
					{		
						if( !isPassed( (Salle)(allowed.toArray())[i] ) ) 
						{
							reponse = (Salle)(allowed.toArray())[i];	
							salleNotPassed = true;						
							passed.add(salleCourante);					
						}
						i++;								
					}
			// si il arrive à un croisement et qu'il a deja tout visité
					if(!salleNotPassed)	 // 
					{
						reponse = (Salle)(allowed.toArray())[1];	
						forbid.add(salleCourante);		// on repassera plus par cette salle	
					}
				}
				else 	// si il a accune salle passée retenu			
				{
					reponse = (Salle)(allowed.toArray())[1];	
					passed.add(salleCourante);					
				}
				break;										
			}
		}
		return reponse;										
	}

/** on met à cours la collection "sallesAccessibles"
* en eliminant toutes les salles interdites
* on passe en Paramentre la collection de salle disponible */
	Collection<Salle> salleAllowed(Collection<Salle> c)				
	{													
		boolean isForbid;	// savoir si est interdite durant la boucle							
		int j;											
		Collection<Salle> reponse = new ArrayList();	
	// s'effectue seulement si il y a des salles interdites déjà précisé			
		if(forbid.size() > 0)					
		{
	// on veut comparé chacune des salles accessible
			for(int i = 0; i < c.size(); i++)			
			{
				isForbid = false;						
				j = 0;								
		// on regarde si la salle accessible est interdite	
				while(!isForbid && j < forbid.size())
				{			
			// si la salle accessible et interdite							
					if( (Salle)(c.toArray())[i] == (Salle)(forbid.toArray())[j] )
					{									
						isForbid = true;		// precise que la salle sera retiré de la collection
					}
					j++;							
				}
		// si c'est une salle autorisée on l'ajoute à la collection	
				if(!isForbid)										
					reponse.add((Salle)(c.toArray())[i]);												
			}
		}
		else		// si aucune salles interdite, on garde telquel								
		{	
			reponse = c;								
		}
		return reponse;									
	}
	
/** fonction qui retourne si une salle a deja etait passée 
 * pour cela on regarde dans notre collection de Salle "passed" */
	boolean isPassed(Salle s)							
	{
		Iterator i = passed.iterator();
		boolean reponse = false;						
		while( !reponse && i.hasNext() )			
		{												
			if(s == i.next() ) 		
				reponse = true;															
		}
		return reponse;									
	}
}
