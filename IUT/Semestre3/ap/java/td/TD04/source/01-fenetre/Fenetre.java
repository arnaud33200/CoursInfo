import java.awt.*;
import javax.swing.*;

/*
public class Fenetre extends JFrame
{
	private JButton b1, b2;
	private JLabel lbl;
	
	public Fenetre(String titre)
	{
		super(titre);
		setBounds(300,300,400,200);
		
		b1 = new JButton("Boutton 1");
		b2 = new JButton("Boutton 2");
		lbl = new JLabel("Texte du Label");
		
		add(b1,"North");
		add(b2,"South");
		add(lbl,"Center");
		
		setVisible(true);
	}
}
*/

/*
public class Fenetre extends JFrame
{
	private Canvas can;
	
	public Fenetre(String titre)
	{
		super(titre);
		setBounds(300,300,400,200);
		can = new Canvas();
		
		add(can, "Center");
		setVisible(true);
		Graphics g = can.getGraphics();
		g.setColor(Color.blue);
		g.drawOval(2,2,20,50);
	}
}
*/


public class Fenetre extends JFrame
{
	private Dessin des;
	
	public Fenetre(String titre)
	{
		super(titre);
		setBounds(300,300,400,200);
		des = new Dessin();
		
		add(des, "Center");
		setVisible(true);
	}
}

