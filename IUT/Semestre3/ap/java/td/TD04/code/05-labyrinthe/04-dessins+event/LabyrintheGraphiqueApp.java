// LabyrintheGraphiqeApp.java

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class LabyrintheGraphiqueApp {
    
    public LabyrintheGraphiqueApp(){
	JFrame.setDefaultLookAndFeelDecorated(true);
	JFrame frame = new JFrame("Grille");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	final Labyrinthe labyrinthe = new Labyrinthe();
	labyrinthe.construireLabyrinthe();
	final Heros bob = new Heros(labyrinthe.getSalleEntree());
	final DessinLabyrintheEtBob dessinLabyrinthe = new DessinLabyrintheEtBob(labyrinthe,bob);
	dessinLabyrinthe.addKeyListener(new KeyAdapter(){
		public void keyPressed(KeyEvent evt) {
		    if (evt.getKeyChar() == 'd') {
			bob.aller(labyrinthe.salleDown(bob.ouSuisJe()));
			dessinLabyrinthe.repaint();
		    }
		    if (evt.getKeyChar() == 'u') {
			bob.aller(labyrinthe.salleUp(bob.ouSuisJe()));
			dessinLabyrinthe.repaint();
		    }
		    if (evt.getKeyChar() == 'l') {
			bob.aller(labyrinthe.salleLeft(bob.ouSuisJe()));
			dessinLabyrinthe.repaint();
		    }
		    if (evt.getKeyChar() == 'r') {
			bob.aller(labyrinthe.salleRight(bob.ouSuisJe()));
			dessinLabyrinthe.repaint();
		    }
		}
	    });
	dessinLabyrinthe.setFocusable(true);
	dessinLabyrinthe.requestFocus();
	frame.setContentPane(dessinLabyrinthe);
	frame.pack();
	frame.setVisible(true);
    }
    
    public static void main (String[] args){
	new LabyrintheGraphiqueApp();
    }
}