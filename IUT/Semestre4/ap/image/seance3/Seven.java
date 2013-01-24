import ij.*;
import ij.process.*;
import ij.gui.*;
import java.awt.*;
import ij.plugin.*;
import ij.plugin.filter.PlugInFilter;

public class Seven implements PlugInFilter
{
	public void run(ImageProcessor ip)
	{
		byte[] pixels = (byte[])ip.getPixels();
	
		int width = ip.getWidth();
		int height = ip.getHeight();
		int ndg;
		for ( int y=0; y<width ; y++ )
			for ( int x=0; x<height ; x++ )
			{
				ndg = pixels[ y*width + x ] & 0xff;
				if ( ndg >= 126 )
					pixels[ y*width + x ] = (byte)255;
				else
					pixels[ y*width + x ] = 0;
			}
	}

	public int setup( String arg, ImagePlus imp)
	{
		new ImageConverter(imp).convertToGray8();
		return DOES_8G+DOES_STACKS+SUPPORTS_MASKING;
	}
}