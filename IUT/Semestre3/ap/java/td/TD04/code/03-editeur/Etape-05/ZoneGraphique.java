import java.awt.*;

public class ZoneGraphique extends Canvas
{
    private Color couleurChoisie = Color.blue;
    
    public ZoneGraphique()
    {
	setBackground(Color.white);
	setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
    }
}