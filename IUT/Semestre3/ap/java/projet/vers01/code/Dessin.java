// Dessin.java
import java.awt.*;
import javax.swing.*;

public class Dessin extends JComponent {

    public static final int unite = 15;
    protected LabyrintheDefaut labyrinthe;
    protected Personnage bob;

    public Dessin(LabyrintheDefaut labyrinthe,Personnage bob)
    {
		this.labyrinthe=labyrinthe;
		this.bob=bob;
		setPreferredSize(new Dimension(labyrinthe.getLargeur()*unite, 
						   labyrinthe.getHauteur()*unite));
    }

    public void paintComponent(Graphics g) 
    {
		Salle[][] salles=labyrinthe.getSalles();

		for(int i=0;i<labyrinthe.getHauteur();i++)
		{
			for(int j=0;j<labyrinthe.getLargeur();j++)
			{
				if(salles[i][j] != null)
				{
					g.setColor(Color.white);
				}
				else
				{
					g.setColor(Color.black);
				}
				g.fillRect(j*unite,i*unite,unite,unite);
			}    
		}
		
		g.setColor(Color.yellow);
		g.fillRect((labyrinthe.positionEntree())[1]*unite,
			   (labyrinthe.positionEntree())[0]*unite,
			   unite,unite);
		
		g.setColor(Color.green);
		g.fillRect((labyrinthe.positionSortie())[1]*unite,
			   (labyrinthe.positionSortie())[0]*unite,
			   unite,unite);
		
		g.setColor(Color.red);
		g.fillRect((bob.position()).getColonne()*unite,
			   (bob.position()).getLigne()*unite,
			   unite,unite);
    }
}
