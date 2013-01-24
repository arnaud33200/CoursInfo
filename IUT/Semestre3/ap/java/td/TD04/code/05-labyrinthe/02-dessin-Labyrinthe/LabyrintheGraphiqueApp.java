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
	DessinLabyrinthe dessinLabyrinthe = new DessinLabyrinthe(labyrinthe);
	frame.setContentPane(dessinLabyrinthe);
	frame.pack();
	frame.setVisible(true);
    }
    
    public static void main (String[] args){
	new LabyrintheGraphiqueApp();
    }
}