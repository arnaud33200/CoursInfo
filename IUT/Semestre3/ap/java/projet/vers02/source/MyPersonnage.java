// MyPersonnage.java

import java.util.*;

public class MyPersonnage extends PersonnageLife
{
    Salle next = new Salle(40, 40);
    ArrayList<Salle> map = new ArrayList<Salle>();										
    ArrayList<Salle> backUp = new ArrayList<Salle>();
    ArrayList<Salle> trapped = new ArrayList<Salle>();	
	int acces[] = new int [1600];									
    boolean back = false;
															
    
    public Salle faitSonChoix(Collection<Salle> sallesAccessibles)
    {
    	boolean foundWay = false;														
    	int i = 0 ;
		
		if( salleCourante instanceof SallePiege && !back)
    	{
			trapped.add(salleCourante);
			clearMap(salleCourante);
			backUp.clear();
		}
		
		if( salleCourante instanceof SallePiege )
    	{
			System.out.println("Taille map = " + map.size() );
			System.out.println("Taille backup = " + backUp.size() );
		}
		
		while( !foundWay && i < sallesAccessibles.size())
		{
			next = (Salle)(sallesAccessibles.toArray())[i];
			if(!map.contains(next))
			{
				foundWay = true;
			}
			i++;
		}
		
    	if((sallesAccessibles.size() == 1 || !foundWay) && !back)  					
    	{
    		back = true;
    		if(!map.contains(salleCourante))
				map.add(salleCourante);
			if(!backUp.contains(salleCourante))
				backUp.add(salleCourante);
		}
		
    	if(back)																			
    	{																					
			if(foundWay)
				back = false;
			else
			{
				backUp.remove(backUp.size() - 1);
				next = backUp.get(backUp.size() - 1);
			}
		}
		else 																				
		{
			if(!backUp.contains(salleCourante))
				backUp.add(salleCourante);
			if(!map.contains(salleCourante))
				map.add(salleCourante);
			
		}
		maj(sallesAccessibles);
		return next;
    }
    protected void clearMap(Salle s)
    {
		int i = backUp.size() - 1;
		int r = -1;
		int j = 0;
		while(j < map.size() && r<0)
		{
			if( acces[j] > 0)
			{
				r = j;
			}
			j++;
		}
			
		while(i > r && j < map.size() && acces[i] == 0 )
		{
			map.remove(map.indexOf(backUp.get(i)));
			i--;
		}
		
	}
	void maj(Collection<Salle> c)
	{
		int r = 0;http://d24w6bsrhbeh9d.cloudfront.net/photo/516973_460s.jpg
		for (int i = 0; i < c.size(); i++)
		{
			if(! (map.contains((Salle)(c.toArray())[i])) )
			{
				r++;
			}
		}
		acces[map.indexOf(salleCourante)] = r;
	}	
}
