import javax.swing.event.*;
import java.awt.event.*;
import javax.swing.*;

public class Click extends MouseInputAdapter {
    private Grille grille;
	
    public Click(Grille g){
	grille=g;
    }
	
    public void mouseClicked(MouseEvent e){
	int absClick = e.getX();
	int ordClick = e.getY();
	/*
	System.out.println("coordonnées click : " + 
			   absClick + " , " + ordClick);
	*/
      	grille.deplacerJeton(absClick,ordClick);
	grille.validate();
      	grille.repaint();
    }
			
}
