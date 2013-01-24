// Labyrinthe.java

public class Labyrinthe {
    private Salle salleEntree;
    private Salle salleSortie;
    private Salle[][] salles;
    private int largeur;
    private int hauteur;

    public Labyrinthe(){
	System.out.println("Labyrinthe : Constructeur par défaut");
    }
    
    public void construireLabyrinthe(){
	largeur=5;
	hauteur=5;
	salles = new Salle[hauteur][largeur];
	
	// création du labyrinthe "à la main"
	salles[0][0]=new Salle();
	salles[0][2]=new Salle();
	salles[0][4]=new Salle();
	salles[1][0]=new Salle();
	salles[1][1]=new Salle();
	salles[1][2]=new Salle();
	salles[1][3]=new Salle();
	salles[1][4]=new Salle();
	salles[2][0]=new Salle();
	salles[2][2]=new Salle();
	salles[3][0]=new Salle();
	salles[3][2]=new Salle();
	salles[3][4]=new Salle();
	salles[4][1]=new Salle();
	salles[4][2]=new Salle();
	salles[4][3]=new Salle();
	salles[4][4]=new Salle();

	salleEntree=salles[0][0];
	salleSortie=salles[3][4];
    }
    
    // Afin de pouvoir répondre à l'adjacence
    // entre deux salles, nous avons besoin
    // de récupérer les coordonnées de la salle
    public int[] getCoordonneesSalle(Salle s){
	int[] res = new int [2];
	res[0]=res[1]=-1;
	int i=0,j=0;
	boolean trouve=false;
	while (!trouve && i<hauteur && j<largeur){
	    if(s == salles[i][j]){
		trouve=true;
		res[0]=i;
		res[1]=j;
	    }
	    else{
		j++;
		if(j==largeur){
		    j=0;
		    i++;
		}
	    }
	}
	return res;
    }
    
    private boolean sallesAdjacentes(Salle s1,Salle s2){
	int[] coordS1 = getCoordonneesSalle(s1);
	int[] coordS2 = getCoordonneesSalle(s2);
	return (coordS1[0] == coordS2[0] 
		&& (coordS1[1] == coordS2[1]+1 || coordS1[1] == coordS2[1]-1)) ||
	    (coordS1[1] == coordS2[1] 
	     && (coordS1[0] == coordS2[0]+1 || coordS1[0] == coordS2[0]-1));
    }

    public Salle[] sallesVoisines(Salle s){
	Salle[] res = new Salle[4];
	int id=0;
	for(int i=0;i<hauteur;i++)
	    for(int j=0;j<largeur;j++)
		if(salles[i][j]!=null)
		    if(sallesAdjacentes(s,salles[i][j]))
			res[id++]=salles[i][j];
	return res;
    }	
    
    public Salle getSalleEntree(){
	return salleEntree;
    }

    public boolean estSalleSortie(Salle s){
	return s == salleSortie;
    }

    public int getHauteur(){
	return hauteur;
    }

    public int getLargeur(){
	return largeur;
    }

    public Salle[][] getSalles(){
	return salles;
    }
    // pour le fun
    /*
    public String toString(){
	String res = 
	    "Labyrinthe : \n" +
	    "hauteur : " + hauteur + "\n" +
	    "largeur : " + largeur + "\n" ;
	for(int i=0;i<hauteur;i++){
	    for(int j=0;j<largeur;j++)
		if(salles[i][j]==null)
		    res+= "X";
		else{
		    if(salles[i][j]==salleEntree)
			res+="E";
		    else if(salles[i][j]==salleSortie)
			res+="S";
		    else
			res+="_";
		}
	    res+="\n";
	}
	return res;
    }
    */
}