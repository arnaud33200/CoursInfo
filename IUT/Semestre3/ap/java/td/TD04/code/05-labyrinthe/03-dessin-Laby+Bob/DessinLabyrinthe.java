// DessinLabyrinthe.java

import java.awt.*;
import javax.swing.*;

public class DessinLabyrinthe extends JComponent {

    public static final int unite = 50;
    protected Labyrinthe labyrinthe;

    public DessinLabyrinthe(Labyrinthe labyrinthe){
	this.labyrinthe=labyrinthe;
	setPreferredSize(new Dimension(labyrinthe.getLargeur()*unite, 
				       labyrinthe.getHauteur()*unite));
    }
    public void paintComponent(Graphics g) {
       

	Salle[][] salles=labyrinthe.getSalles();

	for(int i=0;i<labyrinthe.getHauteur();i++)
	    for(int j=0;j<labyrinthe.getLargeur();j++){
		if(salles[i][j] != null)
		    g.setColor(Color.white);
		else
		    g.setColor(Color.black);
		g.fillRect(j*unite,i*unite,unite,unite);	    
	    }
    }
}