#ifndef FORME_H
#define FORME_H

class Forme
{
	protected:
		char _color;
		
	public:
		virtual void draw() = 0;
		virtual void move( int dx, int dy ) =0;
		
		void setColor( char c );
		char getColor() const;
};

#endif FORME_H
