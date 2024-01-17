#include "Integrateur.h"
// Inclut le fichier d'en-tête pour la classe de base Integrateur.

#include <vector>
// Inclut la bibliothèque standard pour utiliser les vecteurs.

#ifndef __INTEGRATEUR_EULER_H_INCLUDED__
#define __INTEGRATEUR_EULER_H_INCLUDED__
// Vérifie si le fichier "Integrateur_Euler.h" n'a pas été inclus précédemment.

class IntegrateurEulerCromer : public Integrateur {
    // Définit une classe IntegrateurEulerCromer qui hérite de Integrateur.

public:
    // Section publique de la classe.

    // - constructeurs
    IntegrateurEulerCromer (double const& dt = 0.01)
    : Integrateur (dt) {}
    // Constructeur de la classe, avec un paramètre par défaut pour 'dt'.

    // - methodes
    void integre (Oscillateur & oscillateur, double t) override;
    // Déclare la méthode 'integre' qui sera définie ailleurs. 
    // 'override' indique qu'elle remplace une méthode virtuelle de la classe de base.

};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
