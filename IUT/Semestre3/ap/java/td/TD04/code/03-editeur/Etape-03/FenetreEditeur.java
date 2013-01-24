import java.awt.*;
import javax.swing.*;

public class FenetreEditeur extends Frame 
{
    final static int HTaille = 750;
    final static int VTaille = 450;

    public FenetreEditeur()
    {
	setTitle("Editeur Graphique");
	setSize(HTaille,VTaille);
	setBackground(Color.darkGray);
	add(new BarreOutils(),"North");
	setMenuBar(new MenuEditeur());
	show();
    }    
}
