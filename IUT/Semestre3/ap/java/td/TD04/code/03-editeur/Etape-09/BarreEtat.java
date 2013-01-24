import java.awt.*;

public class BarreEtat extends Panel
{
    private Label coord;
    private Label info;

    public BarreEtat ()
    {
	setBackground(Color.lightGray);
	setLayout(new GridLayout(1,2));
	coord = new Label();
	info = new Label();
	add(info);
	add(coord);
    }

    public void afficheMessage(String message)
    {
	info.setText(message);
    }
    
    public void afficheCoord(int x,int y)
    {
	coord.setText("x : " + x + ", y : " + y);
    }
}