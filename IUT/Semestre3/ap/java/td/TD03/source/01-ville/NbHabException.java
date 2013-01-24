public class NbHabException extends Exception
{
    private int nbErr;
    
    public NbHabException(int nbErr)
    {
        this.nbErr = nbErr;
    }
    
    public String toString()
    {
    	return "Nb habitants erroné : " + nbErr ;
    }
}
