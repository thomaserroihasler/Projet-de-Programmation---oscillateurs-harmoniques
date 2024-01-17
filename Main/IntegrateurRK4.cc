#include "IntegrateurRK4.h"
// Inclut le fichier d'en-tête pour la classe IntegrateurRK4.

#include "Oscillateur.h"
// Inclut le fichier d'en-tête pour la classe Oscillateur.

#include "Vecteur.h"
// Inclut le fichier d'en-tête pour la classe Vecteur.

using namespace std;
// Utilise l'espace de noms standard.

void IntegrateurRK4 :: integre (Oscillateur& osc, double t) {
    // Méthode pour intégrer un oscillateur en utilisant la méthode Runge-Kutta d'ordre 4.

    int n = (int) (t/dt + 0.5); 
    // Divise le temps 't' en 'n' intervalles, avec arrondi au plus proche.

    for (unsigned int i(1); i <= n; ++i) {
        // Boucle sur chaque intervalle de temps.

        double Dt(dt/2);
        // Calcul d'un demi-pas de temps.

        // Initialisation des variables k0, k1 et K1 pour le calcul RK4.
        Vecteur k0(osc.get_parametres());
        Vecteur k1(osc.get_derivees());
        Vecteur K1(osc.get_equa_diff(t));

        // Calcul de k2 et mise à jour temporaire de l'oscillateur pour K2.
        Vecteur k2(k1 + Dt * K1);
        osc.set_parametres_val(k0 + Dt * k1);
        osc.set_derivees_val(k1 + Dt * K1);
        Vecteur K2(osc.get_equa_diff(t + Dt));

        // Calcul de k3 et mise à jour temporaire pour K3.
        Vecteur k3(k1 + Dt * K2);
        osc.set_parametres_val(k0 + Dt * k2);
        osc.set_derivees_val(k1 + Dt * K2);
        Vecteur K3(osc.get_equa_diff(t + Dt));

        // Calcul de k4 et mise à jour temporaire pour K4.
        Vecteur k4(k1 + dt * K3);
        osc.set_parametres_val(k0 + dt * k3);
        osc.set_derivees_val(k1 + dt * K3);
        Vecteur K4(osc.get_equa_diff(t + dt));

        // Mise à jour finale des paramètres et dérivées de l'oscillateur.
        osc.set_parametres_val(k0 + (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
        osc.set_derivees_val(k1 + (dt / 6) * (K1 + 2 * K2 + 2 * K3 + K4));
    }
}
