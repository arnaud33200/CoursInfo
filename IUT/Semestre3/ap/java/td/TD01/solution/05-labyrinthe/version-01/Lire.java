
import java.io.*;

public class Lire
{
  static BufferedReader clavier =
    new BufferedReader (new InputStreamReader (System.in));

  public static int lireInt ()
  {
    String ch = "";
    int val = 0;
      try
    {
      ch = clavier.readLine ();
    }
    catch (IOException e)
    {
      System.out.println ("pb clavier");
      System.exit (1);
    }
    ch = ch.trim ();
    try
    {
      val = Integer.parseInt (ch);
    }
    catch (NumberFormatException ex)
    {
      System.out.println ("pas un entier! arret du programme ");
      System.exit (1);
    }
    return val;
  }

  public static double lireDouble ()
  {
    String ch = "";
    double val = 0;
    try
    {
      ch = clavier.readLine ();
    }
    catch (IOException e)
    {
      System.out.println ("pb clavier");
      System.exit (1);
    }
    ch = ch.trim ();
    try
    {
      val = Double.parseDouble (ch);
    }
    catch (NumberFormatException ex)
    {
      System.out.println ("pas un reel! arret du programme");
      System.exit (1);
    }
    return val;
  }

  public static String lireLigne ()
  {
    String ch = "";
    try
    {
      ch = clavier.readLine ();
    }
    catch (IOException e)
    {
      System.out.println ("pb clavier");
      System.exit (1);
    }
    return ch;
  }
}
