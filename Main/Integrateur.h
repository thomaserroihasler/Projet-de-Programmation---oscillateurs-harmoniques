#include <vector>
// Inclut la bibliothèque standard pour utiliser les vecteurs.

#include "Oscillateur.h"
// Inclut le fichier d'en-tête pour la classe Oscillateur.

#ifndef __INTEGRATEUR_H_INCLUDED__
#define __INTEGRATEUR_H_INCLUDED__
// Vérifie si le fichier "Integrateur.h" n'a pas été inclus précédemment.

class Integrateur {
    // Définit une classe abstraite 'Integrateur'.

protected:
    double dt;
    // Variable protégée pour stocker l'intervalle de temps entre les étapes d'intégration.

public:
    // Section publique de la classe.

    // - constructeurs
    Integrateur (const double& dt = 0.01)
    : dt(dt) {}
    // Constructeur avec un paramètre par défaut pour 'dt'.

    // - méthodes
    virtual void integre (Oscillateur& oscillateur, double t) = 0;
    // Déclare une méthode virtuelle pure 'integre' qui doit être définie dans les sous-classes.

};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
