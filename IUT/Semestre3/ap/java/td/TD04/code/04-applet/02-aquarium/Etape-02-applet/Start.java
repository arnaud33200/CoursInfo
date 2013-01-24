import java.applet.Applet;
import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Start extends Applet
{
    Aquarium aquarium;
    Time timer;

    public void init ()
    {
	aquarium = new Aquarium();
	add(aquarium,"Center");
	timer = new Time(aquarium);
	timer.start();
    }
}