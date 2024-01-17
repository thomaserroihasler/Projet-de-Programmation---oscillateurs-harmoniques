#include "Pendule_torssion.h"

// Méthodes de la classe Pendule_de_Torsion

/// Méthode "copie" pour Pendule_de_Torsion
unique_ptr<Pendule_de_Torsion> Pendule_de_Torsion ::specific_copy() const {
    return unique_ptr<Pendule_de_Torsion>(new Pendule_de_Torsion(*this));
}
// Cette méthode crée et renvoie un pointeur unique à une copie de cet objet Pendule_de_Torsion.

/// Méthode "copie" générale pour les oscillateurs
unique_ptr <Oscillateur> Pendule_de_Torsion ::general_copy() const {
    return specific_copy();
}
// Cette méthode utilise la méthode specific_copy pour renvoyer un pointeur unique à un Oscillateur.

/// Équation différentielle du Pendule de Torsion
Vecteur Pendule_de_Torsion :: equa_diff (double t) {
    return ((-1/inertie) * (coef_torsion * get_parametres() + frottement * get_derivees())); 
}
// Calcule et renvoie le résultat de l'équation différentielle du pendule de torsion.

/// Dessine le Pendule de Torsion
void Pendule_de_Torsion :: dessine() {
    support->dessine(*this);
}
// Appelle la méthode dessine de l'objet support, en lui passant cet objet Pendule_de_Torsion.

/// Affichage interne d'un Pendule de Torsion
ostream& Pendule_de_Torsion :: affiche (ostream& sortie) const {
    sortie << "l'angle est: " << parametres; sortie << endl;
    sortie << "la vitesse angulaire est: " << derivees; sortie << endl;
    return sortie;
}
// Affiche l'angle et la vitesse angulaire du pendule de torsion sur le flux de sortie.

/// Renvoie le type d'oscillateur
string Pendule_de_Torsion:: type () const {
    return "Pendule de Torsion";
}
// Renvoie une chaîne de caractères représentant le type de l'oscillateur (utile pour distinguer les différents oscillateurs dans un système).
