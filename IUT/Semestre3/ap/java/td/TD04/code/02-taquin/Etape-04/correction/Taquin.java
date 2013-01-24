import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Taquin extends JFrame 
{
    private Grille grille;

    private int nbLignesTaquin;
    private int nbColonnesTaquin;

    final static int largeurFenetre = 600;
    final static int hauteurFenetre = 400;
 
    private Click click;

    private JPanel controle;
    private JButton bLPlus, bLMoins, bCPlus, bCMoins, bReInit;

    
    class bRClick implements ActionListener
    {
	public void actionPerformed(ActionEvent e)
	{
	    reInit();
	}
    }
	
    class bLClick implements ActionListener
    {
	private int valIncr;

	public bLClick(int valIncr)
	{
	    this.valIncr=valIncr;
	}
	
	public void actionPerformed(ActionEvent e)
	{
	    int tmp = nbLignesTaquin+valIncr; 
	    if( tmp > 1 && tmp < 9)
		nbLignesTaquin = tmp;
	    reInit();
	}
    }
    
    class bCClick implements ActionListener
    {
	private int valIncr;
	
	public bCClick(int valIncr)
	{
	    this.valIncr=valIncr;
	}
	
	public void actionPerformed(ActionEvent e)
	{
	    int tmp = nbColonnesTaquin+valIncr; 
	    if( tmp > 1 && tmp < 14)
		nbColonnesTaquin = tmp;
	    reInit();
	}
    }
    
    public Taquin(String titre)
    {
	super(titre);

	nbLignesTaquin = 5;
	nbColonnesTaquin = 5;
	
	setBounds(0,0,largeurFenetre,hauteurFenetre);
	int x_0 = (largeurFenetre - Grille.getLargeurColonne()*nbColonnesTaquin)/2;
	int y_0 = (hauteurFenetre - Grille.getHauteurLigne()*nbLignesTaquin)/2 - 40;
	grille=new Grille(nbLignesTaquin,nbColonnesTaquin,x_0,y_0);
	click = new Click(grille);
	controle = new JPanel();
	bLPlus = new JButton("nb. lig. +");
	bLMoins = new JButton("nb. lig. -");
	bCPlus = new JButton("nb. col. +");
	bCMoins = new JButton("nb. col. -");
	bReInit = new JButton("reinitialiser");
	
	bReInit.addActionListener(new bRClick());
	bLPlus.addActionListener(new bLClick(+1));
	bLMoins.addActionListener(new bLClick(-1));
	bCPlus.addActionListener(new bCClick(1));
	bCMoins.addActionListener(new bCClick(-1));
	
	controle.add(bLMoins);
	controle.add(bLPlus);
	controle.add(bCMoins);
	controle.add(bCPlus);
	controle.add(bReInit);

	grille.addMouseListener(click); 

	add(controle,"North");
	add(grille,"Center");
	setVisible(true);
    }
    
    public void reInit()
    {
	
	grille.removeMouseListener(click);
	remove(grille);
	repaint();
	int x_0 = (largeurFenetre - Grille.getLargeurColonne()*nbColonnesTaquin)/2;
	int y_0 = (hauteurFenetre - Grille.getHauteurLigne()*nbLignesTaquin)/2 - 40;
	grille = new Grille(nbLignesTaquin,nbColonnesTaquin,x_0,y_0);
	click = new Click(grille);
	grille.addMouseListener(click);
	add(grille,"Center"); 
	setVisible(true);
    }

    public static void main (String args [])
    {
	new Taquin("Jeu de Taquin");
    }
}
