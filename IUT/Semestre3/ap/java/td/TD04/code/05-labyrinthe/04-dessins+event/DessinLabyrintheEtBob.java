// DessinLabyrintheEtBob.java

import java.awt.*;

public class DessinLabyrintheEtBob extends DessinLabyrinthe {

    private Heros bob;

    public DessinLabyrintheEtBob(Labyrinthe labyrinthe,Heros bob){
	super(labyrinthe);
	this.bob=bob;
    }
    
    public void paintComponent(Graphics g) {
	super.paintComponent(g);
	Salle salleCourante=bob.ouSuisJe();
	int[] coordonnees=labyrinthe.getCoordonneesSalle(salleCourante);
	g.setColor(Color.red);
	g.fillOval(coordonnees[1]*unite,coordonnees[0]*unite,unite,unite);
    }
}