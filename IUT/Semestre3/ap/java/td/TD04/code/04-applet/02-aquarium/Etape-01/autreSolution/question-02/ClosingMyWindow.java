import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ClosingMyWindow extends WindowAdapter
{
    private JFrame jFrame;
    
    public ClosingMyWindow(JFrame jFrame)
    {
	this.jFrame=jFrame;
    }
    
    public void windowClosing(WindowEvent e)
    {
	int n = JOptionPane.showConfirmDialog(jFrame,
					      "Quitter ?",
					      "Attention", 
					      JOptionPane.YES_NO_OPTION);
	if(n == JOptionPane.OK_OPTION)
	    jFrame.dispose();
    }
}