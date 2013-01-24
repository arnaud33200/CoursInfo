import java.awt.*;

public class Jeton {
    private int abs;
    private int ord;
    private int numero;
    private Color couleur;

    public Jeton(int abs,int ord,int numero,Color couleur) {
	this.abs = abs;
	this.ord = ord;
	this.numero = numero;
	this.couleur = couleur;
    }
    public int getAbs(){
	return abs;
    }
    public int getOrd(){
	return ord;
    }
    public int getNumero(){
	return numero;
    }
    public Color getCouleur(){
	return couleur;
    }

}