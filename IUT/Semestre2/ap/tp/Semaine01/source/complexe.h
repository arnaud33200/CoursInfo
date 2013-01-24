#ifndef COMPLEXE_H
#define COMPLEXE_H

class Complexe
{
	private:
/// ########### les atributs ################### ///	
		int my_re;
		int my_im;
		
	public:
/// ########### les methodes ################### ///	
		void afficher();
		void addition( Complexe c, Complexe & r );
		void soustraire( Complexe c, Complexe & r );
		void multiplier( Complexe c, Complexe & r );
		void diviser( Complexe c, Complexe & r );
		
/// ########### les constructeur ############### ///			
		Complexe();
		Complexe(int r, int i);
		
/// ########### les accesseurs ################# ///	
		int getRe();
		int getIm();
		
		void setRe( int r );
		void setIm( int i );
};

#endif
