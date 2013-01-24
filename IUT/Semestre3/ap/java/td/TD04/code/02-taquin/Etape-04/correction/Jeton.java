import java.awt.*;

public class Jeton
{
    private int abs;
    private int ord;
    private int numero;
    private Color couleur;

    public Jeton(int abs,int ord,int numero,Color couleur)
    {
	this.abs = abs;
	this.ord = ord;
	this.numero = numero;
	this.couleur = couleur;
    }
    public Jeton(Jeton j)
    {
	abs=j.abs;
	ord=j.ord;
	numero=j.numero;
	couleur=j.couleur;
    }
    public int getAbs()
    {
	return abs;
    }
    public int getOrd()
    {
	return ord;
    }
    public int getNumero()
    {
	return numero;
    }
    public Color getCouleur()
    {
	return couleur;
    }
    public String toString()
    {
	return "Jeton : ( " + abs + " , " + ord + " ) " + numero + " - " + couleur ;
    }
    public void setAbs(int abs)
    {
	this.abs=abs;
    }
    public void setOrd(int ord)
    {
	this.ord=ord;
    }
    public void setNumero(int numero)
    {
	this.numero=numero;
    }
    public void setCouleur(Color couleur)
    {
	this.couleur=couleur;
    }
}