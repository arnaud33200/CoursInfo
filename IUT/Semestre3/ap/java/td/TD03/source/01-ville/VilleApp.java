public final class VilleApp
{
    public static void main (String args [])
    {
         try 
         { // Capture de l’exception
              Ville v = new Ville("Shanghai",-1);
         }
         catch(NbHabException e)
         {
                // l’exception capturée, on la traite
              System.out.println(e);
         }
       	/*finally
       	{
                // bloc exécuté quoiqu’il advienne
                // permet de faire du nettoyage au besoin
              System.out.println("finally");
         } */
    }
}
