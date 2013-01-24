import java.awt.event.*;
import java.awt.*;

public class ChangeCouleur implements ActionListener
{
    private Color couleur;
    private Dessin dessin;

    public ChangeCouleur(Color couleur,Dessin dessin)
    {
	this.couleur=couleur;
	this.dessin=dessin;
    }

    public void actionPerformed(ActionEvent e)
    {
	dessin.setColor(couleur);
	dessin.repaint();
    }
}