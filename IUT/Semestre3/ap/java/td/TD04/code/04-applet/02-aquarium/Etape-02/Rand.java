import java.util.*;

public final class Rand 
{
    private final static Random r=new Random(System.currentTimeMillis());
    
    public static int randomValue(int min,int max) 
    {
	return r.nextInt(max-min)+min;
    }
}
