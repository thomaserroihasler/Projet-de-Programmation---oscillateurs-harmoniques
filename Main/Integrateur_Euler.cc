#include "Integrateur_Euler.h"
// Inclut le fichier d'en-tête pour l'intégrateur d'Euler-Cromer.

#include <iostream>
// Inclut la bibliothèque standard d'entrée/sortie.

#include <vector>
// Inclut la bibliothèque standard pour utiliser les vecteurs.

using namespace std;
// Utilise l'espace de noms standard.

void IntegrateurEulerCromer :: integre (Oscillateur & oscillateur, double t) {
    // Méthode pour intégrer l'oscillateur sur un intervalle de temps 't'.
	
    int n = (int) (t/dt + 0.5); 
    // Calcule le nombre de pas de temps nécessaires.

    for (unsigned int i(1); i <= n; ++i) {
        // Boucle sur chaque pas de temps.

        // Calcul des nouvelles dérivées de l'oscillateur.
        Vecteur test((dt * oscillateur.get_equa_diff(t)) + oscillateur.get_derivees());
        oscillateur.set_derivees(test);

        // Mise à jour des paramètres de l'oscillateur.
        test = (dt * oscillateur.get_derivees()) + oscillateur.get_parametres();
        oscillateur.set_parametres(test);
    }
}
