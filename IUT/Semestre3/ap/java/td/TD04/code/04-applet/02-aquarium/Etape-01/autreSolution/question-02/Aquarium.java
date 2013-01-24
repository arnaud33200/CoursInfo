import java.awt.*;
import javax.swing.*;

public class Aquarium extends JFrame
{
    private final static int HEIGHT=400;
    private final static int WIDTH =800;

    public Aquarium()
    {
	super("Aquarium");
	setSize(WIDTH,HEIGHT);//ou bien setBounds(0,0,WIDTH,HEIGHT);
	setVisible(true);
	addWindowListener(new ClosingMyWindow(this)); // awt
    }
}