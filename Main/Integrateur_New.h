#include "Integrateur.h"
// Inclut le fichier d'en-tête pour la classe de base Integrateur.

#include <vector>
// Inclut la bibliothèque standard pour utiliser les vecteurs.

#ifndef __INTEGRATEUR_NEW_H_INCLUDED__
#define __INTEGRATEUR_NEW_H_INCLUDED__
// Vérifie si le fichier "Integrateur_New.h" n'a pas été inclus précédemment.

class IntegrateurNewmark : public Integrateur {
    // Définit une classe IntegrateurNewmark qui hérite de Integrateur.

private:
    double erreur;
    // Variable privée pour stocker le seuil d'erreur.

public:
    IntegrateurNewmark (const double& dt, double erreur)
    : Integrateur (dt), erreur(erreur) {}
    // Constructeur qui initialise la classe avec un intervalle de temps 'dt' et un seuil d'erreur.

    void integre (Oscillateur& oscillateur, double t) override;
    // Déclare la méthode 'integre' qui sera définie ailleurs. 
    // 'override' indique qu'elle remplace une méthode virtuelle de la classe de base.

};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
