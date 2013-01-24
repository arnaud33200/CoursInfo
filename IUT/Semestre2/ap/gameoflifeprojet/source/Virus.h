#ifndef VIRUS_H
#define VIRUS_H

/**
 * \file Virus.h
 * \brief unité perturbateur du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>

#include "Unite.h"

using namespace sf;

/** 
 * \class Virus
 * \brief classe qui gère un Virus
*/
class Virus : public Unite
{
	private:
		bool _target;
		float _dy;
		float _dx;
		float _timeDir;
		Clock _timeLife, _timeIncub;
		float _timePassed, _timeInc;
		
	public:
	
/// ###################### CONSTRUCTOR & DESTRUCTOR ####################

		Virus();
		Virus( const float & x, const float & y );
		Virus( const Virus & v );
		~Virus( );

/// ###################### MOUVEMENT VIRUS ####################
		
		void move(const float & w, const float & h );
		
/// ###################### ACCESSEURS VIRUS ####################
		
		bool getTarget() const;
		float getTimeLife() const;
		float getTimeIncub() const;
		float getTimePassed() const;
		float getTimeIncPassed() const;
		
		void setTarget( const bool & t );
		void setResetLife();
		void setResetIncub();
		void setTimePassed( const float & t );
		void setTimeIncPassed( const float & t );
};

#endif // VIRUS_H
