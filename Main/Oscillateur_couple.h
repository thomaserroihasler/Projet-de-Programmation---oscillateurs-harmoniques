#include "Oscillateur.h"
// Inclut le fichier d'en-tête pour la classe Oscillateur.

class Oscillateur_couple: public Oscillateur {
    // Définit la classe Oscillateur_couple qui hérite de la classe Oscillateur.

public:
    // Constructeur par défaut.
    Oscillateur_couple (SupportADessin* & support)
    : Oscillateur(support) {}
    // Ce constructeur initialise un Oscillateur_couple avec un support à dessin.
    // Il appelle le constructeur de la classe de base Oscillateur.

    // Constructeur avec paramètres et dérivées.
    Oscillateur_couple (SupportADessin* & support, Vecteur& para, Vecteur& deri)
    : Oscillateur(support, para, deri) {}
    // Ce constructeur initialise un Oscillateur_couple avec un support à dessin,
    // un vecteur de paramètres et un vecteur de dérivées.
    // Il appelle également le constructeur correspondant de la classe de base Oscillateur.

};
