// Fichier Boite.h

#ifndef BOITE_H
#define BOITE_H

#include "Point.h"

class Boite {
  private:
    Point my_bas_gauche;        // Coin bas-gauche du rectangle englobant
    Point my_haut_droite;       // Coin haut-droit du rectangle englobant
    Point* my_points;           // Tableau contenant les points
    int my_nb_alloues;          // Nb de points alloues dynamiquement dans my_points
    int my_nb_points;           // Nb de points effectivement stockes dans my_points
    Boite();    // constructeur interdit d'usage : la notion de boite englobante
                // n'a de sens qu'a partir de un point (au moins)
    void agrandir();    // agrandit le tableau de points si besoin (lors de l'ajout d'un point)
  public:
    Boite( const Point & p );   // Construit une boite englobant un point
    ~Boite();                   // destructeur
    void affiche() const;
    bool interieur( const Point & p ) const; // Retourne vrai si p est dans la boite
    void ajouterPoint( const Point & p );    // Ajout d'un nouveau point ET mise a
                                             // jour de la boite englobante
    void supprimerPoint( const Point & p );  // Enlever point du tableau (si present)
                                             // ET mise a jour de la  boite englobante
                                             // (si necessaire)
};

#endif // #ifndef BOITE_H
