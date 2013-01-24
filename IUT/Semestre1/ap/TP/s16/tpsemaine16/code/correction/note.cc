# include<iostream>
# include<cstdlib>
   
   using namespace std ;
   
   #define MAX_ETUDIANTS 30
   #define MAX_NOTES 6
   #define NOTE_MAXIMALE 20
   typedef bool damier[6][6];
   
void saisir_notes ( double notes[][MAX_NOTES], int &nb_etu, int &nb_notes )
{
	do
	{
		cout << "nb eleve ? : "; cin >> nb_etu;
		cout << "nb notes ? : "; cin >> nb_notes;
	}
	while ( nb_etu < 0 || nb_etu > MAX_ETUDIANTS || nb_notes < 0 || nb_notes > MAX_NOTES );
	
	for ( int i=0; i < nb_etu; i++ )
	{
		cout << "etudiant N° " << i+1 << endl;
		for ( int j=0; j < nb_notes; j++ )
		{
			do
			{
				cout << "      note " << j+1 << " : "; 
				cin >> notes[i][j];
			}
			while ( notes[i][j] < 0 || notes[i][j] > NOTE_MAXIMALE );
		}
				
	}			
}

double moyenne_note ( double notes[][MAX_NOTES], int numero_note, int nb_etu )
{
	double cpt=0;
	
	for ( int i=0; i < nb_etu; i++ )
		cpt+=notes[i][numero_note];
	return ( cpt / nb_etu );
}

double moyenne_etudiant ( double notes[][MAX_NOTES], int numero_etudiant, int nb_notes )
{
	double cpt=0;
	for ( int j=0; j < nb_notes; j++ )
		cpt+=notes[numero_etudiant][j];
	return ( cpt / nb_notes );
}

   int main () {

      double notes_etu[MAX_ETUDIANTS][MAX_NOTES];
      int nb_etu, nb_notes;
      saisir_notes ( notes_etu, nb_etu, nb_notes );
      int numero_etu = 1;
      cout << " Moyenne de l ' etudiant " << numero_etu << " : "
         << moyenne_etudiant(notes_etu,numero_etu,nb_notes) << endl ;
      int numero_note =2;
      cout << " Moyenne des etudiants sur la note " << numero_note << " : "
         << moyenne_note ( notes_etu , numero_note , nb_etu ) << endl ;
        return 0;
   }
