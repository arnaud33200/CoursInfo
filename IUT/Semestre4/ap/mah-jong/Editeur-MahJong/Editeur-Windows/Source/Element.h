#ifndef ELEMENT_H
#define ELEMENT_H

#include "constantes.h"

class Element
{
	protected:

		float _x;
		float _y;
		float _w;
		float _h;

	public:

/// ####################### CONSTRUCTEUR DESTRUCTEUR ###################
		Element(const float & x, const float & y, const float & w, const float & h );
		Element();
		~Element();

/// ####################### ACCESSEUR LECTURE ##########################
		float getX() const;
		float getY() const;
		float getW() const;
		float getH() const;

/// ####################### ACCESSEUR ECRITURE #########################
		void setX (const float & x );
		void setY (const float & y );
		void setW (const float & w );
		void setH (const float & h );
};

#endif // ELEMENT_H
