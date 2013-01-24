#include <vector>
#include <cstdlib>

using namespace std;

// un sommet à un numéro et à une valeur
struct Sommet
{
	int _num;
	int _val;
};

// boite qui indique les relation entre chaque
// sommet, plusieur boite peuvent pointé vers le meme
// sommet et chaque boite peut pointé vers une suivante
class Boite
{
	public:
		Sommet * _som;
		Boite * _suiv;
		
		Boite()
		{
			_som = NULL;
			_suiv = NULL;
		}
		
		Boite( Sommet* s )
		{ 
			_som = s;
			_suiv = NULL;
		}
		
		~Boite() {}
};

// la liste d'adjascence est un tableau de boite
// chaque boite représente un sommet du graphe
// ainsi pour chaque boite, on peut avoir accés à la suivante
// une liste des sommets controlent les sommets déja existant
class ListeAdja
{
	private:
		vector<Boite> _listElem;
		vector<Sommet*> _listSom;
		
	public:
	
		ListeAdja()
		{ }
		
		~ListeAdja()
		{
			for ( int i=0; i< _listSom.size(); i++ )
			{
				if( _listSom[i] != NULL )
					delete _listSom[i];
			}
		}
		
	// retourne les voisins du sommet n dans tableau
	// null si pas de voisin
		vector<Sommet*> voisin( int n )
		{
			vector<Sommet*> vois;
			int i;
			Boite conc;		// la boite concerné
			
			if( i=chercheElem(n) != -1 )
			{
				conc = _listElem[i];
				do
				{
					vois.push_back( conc._som );
					conc = *conc._suiv;
				}
				while( conc._suiv != NULL );
			}
			return vois;
		}
		
		bool ajoutSommet( int s, int v)
		{
			if ( chercheSom(s) == -1 )		// sommet non présent
			{
				_listSom.push_back( new Sommet );
				_listSom[_listSom.size()-1]->_num = s;
				_listSom[_listSom.size()-1]->_val = v;
				
				if ( chercheElem(s) == -1 )		//
					_listElem.push_back( Boite(_listSom[_listSom.size()-1]) );
				return true;
			}
			return false;
		}
		
		int chercheSom( int s )
		{
			for( int i=0; i<_listSom.size(); i++ )
				if( _listSom[i]->_num == s )
					return i;
			return -1;
		}
		
		int chercheElem( int s )
		{
			for( int i=0; i<_listElem.size(); i++ )
				if( _listElem[i]._som->_num == s )
					return i;
			return -1;
		}
		
		bool ajouterVoisin( int s, int v )
		{
			return true;
		}
	
};

int main()
{
	
}
