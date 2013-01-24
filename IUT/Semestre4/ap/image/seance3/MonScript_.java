import ij.*;
import ij.process.*;
import ij.gui.*;
import java.awt.*;
import ij.plugin.*;
import ij.plugin.filter.PlugInFilter;

public class MonScript_ implements PlugInFilter
{
	public void run(ImageProcessor ip)
	{
		IJ.showMessage("Affichage de la joconde");
		ip.invert();
	}

	public int setup( String arg, ImagePlus imp)
	{
		if ( arg.equals("about") )
			return DONE;
		new ImageConverter(imp).convertToGray8();
		return DOES_8G+DOES_STACKS+SUPPORTS_MASKING;
	}
}