#include "Integrateur.h"
// Inclut le fichier d'en-tête pour la classe de base Integrateur.

#include <vector>
// Inclut la bibliothèque standard pour utiliser les vecteurs.

#ifndef __INTEGRATEURRK4_H_INCLUDED__
#define __INTEGRATEURRK4_H_INCLUDED__
// Vérifie si le fichier "IntegrateurRK4.h" n'a pas été inclus précédemment.

class IntegrateurRK4 : public Integrateur {
    // Définit une classe IntegrateurRK4 qui hérite de Integrateur.

public:
    // Section publique de la classe.

    // - constructeur
    IntegrateurRK4 (double const& dt)
    : Integrateur (dt) {}
    // Constructeur qui initialise la classe avec un intervalle de temps 'dt'.

    // - méthode
    void integre (Oscillateur& oscillateur, double t) override;
    // Déclare la méthode 'integre' qui sera définie ailleurs. 
    // 'override' indique qu'elle remplace une méthode virtuelle de la classe de base.

};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
