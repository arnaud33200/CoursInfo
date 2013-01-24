// LabyrintheApp.java

import java.lang.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;

public class LabyrintheApp {

    public static void main (String[] args)
    {
	

		// modele
		Labyrinthe labyrinthe = new LabyrintheDefaut();
		labyrinthe.creerLabyrinthe(args[0]);
		Personnage bob = new MyPersonnage();
		labyrinthe.entrer(bob);
		int cpt=0;

		// vue
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame frame = new JFrame("Labyrinthe");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dessin dessin = new Dessin((LabyrintheDefaut)labyrinthe,bob);

		dessin.setFocusable(true);
		dessin.requestFocus();
		frame.setContentPane(dessin);
		frame.pack();
		frame.setVisible(true);

		while(!labyrinthe.sortir(bob))
		{
			Collection<Salle> sallesAccessibles = 
			labyrinthe.sallesAccessibles(bob);
			Salle destination = bob.faitSonChoix(sallesAccessibles);
			bob.aller(destination);
			cpt++;
		
			//rafraichissement de la vue
			frame.repaint();

			// on fait une pause
			try
			{
				Thread.currentThread().sleep(80);
			}
			catch(InterruptedException ie)
			{
			}
			
			
		}
	System.out.println("Nombre de deplacements : " + cpt);
	frame.dispose();
    }
}
