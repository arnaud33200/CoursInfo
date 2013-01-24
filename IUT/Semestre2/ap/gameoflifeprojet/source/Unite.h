#ifndef UNITE_H
#define UNITE_H

/**
 * \file Unite.h
 * \brief unité du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

/** 
 * \class Unite.h
 * \brief classe mère qui gère une unité
*/
class Unite
{
	protected:
	
		float _x;
		float _y;
		
	public:
	
/// ####################### CONSTRUCTEUR DESTRUCTEUR ###################
	
		Unite(const float & x, const float & y);
		Unite();
		~Unite();

/// ####################### ACCESSEUR LECTURE ##########################
		
		float getX ( ) const;
		float getY ( ) const;
		
/// ####################### ACCESSEUR ECRITURE #########################

		void setX (const float & x );
		void setY (const float & y );
};

#endif // UNITE_H
