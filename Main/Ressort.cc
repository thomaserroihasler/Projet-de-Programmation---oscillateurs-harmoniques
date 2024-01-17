#include "Ressort.h"
#include "SupportADessin.h"
#include "Constantes.h"

using namespace std;

/// méthode "copie" - qui renvoie un pointeur d'allocation dynamique pour la class hétérogène de système

unique_ptr<Ressort> Ressort ::specific_copy() const {return unique_ptr<Ressort>(new Ressort(*this));}

/// méthode "copie" - qui prend le pointeur Ressort de "specific copie" et renvoie un pointeur Oscillateur

unique_ptr <Oscillateur> Ressort ::general_copy() const {return specific_copy();}

/// equation differentiel du Ressort

Vecteur Ressort :: equa_diff (double t) {
Vecteur axe_un(axe.vect_uni()); // produit scalaire avec g n'est pas possible car notre porduit scalaire modifie la dimension des vecteurs (plongement dimensionel)
Vecteur grav (g^axe_un, true); // creer un vecteur 1D de valeur du produit scalaire
return (-raideur/masse)*get_parametres() + (-frottement/masse)*get_derivees() + grav;}

/// desine Ressort
void Ressort :: dessine()  
{ support->dessine(*this);}

/// renvoie le type d'oscillateur - utilisé dans l'affichage de systeme pour distinguer les differents oscillateurs
string Ressort:: type () const {
return "Ressort";
}

///afichage interne d'un Ressort
ostream& Ressort :: affiche(std::ostream& sortie) const {
sortie << "la position est: " << parametres << endl;
sortie << "la vitesse est: " << derivees << endl;
return sortie;
}

///affichage externe d'un Pendule
std::ostream& operator<<(std::ostream& sortie, Ressort const& p) {
return p.affiche(sortie);	
}
