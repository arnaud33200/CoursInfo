import java.awt.*;
import java.awt.event.*;

public class APropos extends Dialog implements ActionListener
{
    private Image image;
    
    public APropos (Frame parent)
    {
	super(parent,"A propos",true);
	//	System.out.println(getToolkit());
	Button bouton = new Button("OK");
	bouton.addActionListener(this);
	Label texte =  new Label("D'apres le Chapitre 'Construire \nune  interface  graphique'   de \n'Java    La    Synthese'    de \n          G. Clavel, \n          N. Mirouze, \n          S. Munerot, \n          E. Pichon, et \n          M. Soukal.");
	setLayout(null);
	bouton.setBounds(294,400,206,28);
	texte.setBounds(294,50,206,390);
	add(bouton);
	add(texte);
	addWindowListener(new AProposListener(this));
	setSize(500,428);
	setResizable(false);
	Toolkit toolkit = getToolkit();
	image = toolkit.getImage("ima.JPG");
    }
    public void paint(Graphics g)
    {
	g.drawImage(image,0,0,284,428,this);
    }
    public void actionPerformed(ActionEvent e)
    {
	dispose();
    }
}

class AProposListener extends WindowAdapter
{
    Dialog dialogue;
    public AProposListener(Dialog dialogue)
    {
	this.dialogue = dialogue;
    }
    public void windowClosing(WindowEvent e)
    {
	dialogue.dispose();
    }
}