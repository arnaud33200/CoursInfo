// LabyrintheGraphiqeApp.java

import java.awt.*;
import javax.swing.*;

public class LabyrintheGraphiqueApp {
    
    public LabyrintheGraphiqueApp(){
	JFrame.setDefaultLookAndFeelDecorated(true);
	JFrame frame = new JFrame("Grille");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	Labyrinthe labyrinthe = new Labyrinthe();
	labyrinthe.construireLabyrinthe();
	Heros bob = new Heros(labyrinthe.getSalleEntree());
	DessinLabyrintheEtBob dessinLabyrinthe = new DessinLabyrintheEtBob(labyrinthe,bob);
	frame.setContentPane(dessinLabyrinthe);
	frame.pack();
	frame.setVisible(true);
    }
    
    public static void main (String[] args){
	new LabyrintheGraphiqueApp();
    }
}