import java.awt.*;
import java.awt.event.*;

public class GestionnaireFenetre extends WindowAdapter
{
    public void windowClosing(WindowEvent e)
    {
	System.exit(0);
    }
}