#include "Integrateur_New.h"
// Inclut le fichier d'en-tête pour la classe IntegrateurNewmark.

#include "Oscillateur.h"
// Inclut le fichier d'en-tête pour la classe Oscillateur.

#include "Vecteur.h"
// Inclut le fichier d'en-tête pour la classe Vecteur.

using namespace std;
// Utilise l'espace de noms standard.

void IntegrateurNewmark :: integre (Oscillateur& oscillateur, double t) {
    // Méthode pour intégrer l'oscillateur sur un intervalle de temps 't' 
    // en utilisant la méthode de Newmark.

    int n = (int) (t/dt + 0.5); 
    // Détermine le nombre de pas de temps à utiliser.

    for (unsigned int i(1); i <= n; ++i) {
        // Boucle sur chaque pas de temps.

        // Calcul initial pour les valeurs de l'oscillateur.
        Vecteur s(oscillateur.get_equa_diff(t));
        Vecteur param(oscillateur.get_parametres());
        Vecteur derivee(oscillateur.get_derivees());
        
        // Initialisation des variables pour la boucle 'do-while'.
        Vecteur q(param);
        Vecteur ss(oscillateur.get_equa_diff(t));
        Vecteur param_(param);
        Vecteur derivee_(derivee);

        // Boucle 'do-while' pour affiner la solution.
        do {
            q = param_;
            ss = oscillateur.get_equa_diff(t + dt);
            derivee_ = derivee + (dt/2) * (s + ss);
            param_ = param + dt * derivee + (dt * dt) / 3 * ((1 / 2) * s + ss);
        } while((param_.norme() - q.norme()) >= erreur);
        
        // Mise à jour des paramètres et dérivées de l'oscillateur.
        oscillateur.set_parametres(param_);
        oscillateur.set_derivees(derivee_);
    }
}
