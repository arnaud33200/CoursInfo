import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
import java.util.*;

public class ChangeColor implements ActionListener
{
	private Dessin des;
	private Color couleur;
	
	public ChangeColor( Dessin d, Color c )
	{
		des = d;
		couleur = c;
	}
	
	public void actionPerformed(ActionEvent e)
	{
		System.out.println("changement de couleur");
		des.setCouleur(couleur);
		des.repaint();
	}
}
