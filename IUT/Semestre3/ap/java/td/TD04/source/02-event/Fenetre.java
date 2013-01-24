import java.awt.*;
import javax.swing.*;
import java.util.*;


public class Fenetre extends JFrame
{
	private Dessin des;
	private JButton b1;
	private JButton b2;
	
	public Fenetre(String titre)
	{
		super(titre);
		setBounds(300,300,400,200);
		des = new Dessin( Color.blue );
		b1 = new JButton("couleur de base");
		b2 = new JButton("couleur rouge");
		
		add(des, "Center");
		add(b1, "North");
		add(b2, "South");
		setVisible(true);
		
		b2.addActionListener( new ChangeColor(des,Color.red) );
		b1.addActionListener( new ChangeColor(des, Color.blue) );
	}
}

