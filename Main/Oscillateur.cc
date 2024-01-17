#include "Oscillateur.h"
#include "SupportADessin.h"
#include <iostream>
#include <cmath>
// Inclut les fichiers d'en-tête nécessaires.

using namespace std;
// Utilise l'espace de noms standard.

// - Méthodes

/// Méthode "copie"
unique_ptr<Oscillateur> Oscillateur :: general_copy() const {return nullptr;};
// Cette méthode virtuelle renvoie un pointeur unique à nullptr. 
// Elle est destinée à être redéfinie dans les sous-classes pour la copie polymorphique.

/// Dessine Oscillateur
void Oscillateur :: dessine() {
    support->dessine(*this);
}
// Cette méthode appelle la méthode 'dessine' de l'objet 'support', 
// en lui passant l'instance actuelle de 'Oscillateur'.

/// Affichage interne d'un Oscillateur
ostream& Oscillateur :: affiche (ostream& sortie) const {
    sortie << "les parametres sont: " << parametres; sortie << endl;
    sortie << "les derivees sont: " << derivees; sortie << endl;
    return sortie;
}
// Affiche les paramètres et les dérivées de l'oscillateur sur le flux de sortie.

// - Opérateurs

/// Affichage externe (utilise l'affichage interne)
std::ostream& operator << (std::ostream& sortie, Oscillateur const& osci) {
    return (osci.affiche(sortie));
}
// Surcharge de l'opérateur '<<' pour permettre l'affichage des informations 
// d'un objet 'Oscillateur' en utilisant l'opérateur de flux standard.
