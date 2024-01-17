#include "Pendule.h"
#include "Constantes.h"
#include <cmath>

/// équation differentiel du Pendule
Vecteur Pendule :: equa_diff (double t) {
Vecteur unit (1,true);
return (-1*(g.norme() / longueur))*sin(parametres.valeur())*unit + ((-1*frottement)/(masse*pow(longueur,2)))*get_derivees(); 
}

/// dessine Pendule
void Pendule :: dessine()  
{ support->dessine(*this);}

/// méthode "copie" - qui renvoie un pointeur d'allocation dynamique pour la class hétérogène de système

unique_ptr<Pendule> Pendule ::specific_copy() const {return unique_ptr<Pendule>(new Pendule(*this));}

/// méthode "copie" - qui prend le pointeur Pendule de "specific copie" et renvoie un pointeur Oscillateur

unique_ptr <Oscillateur> Pendule ::general_copy() const {return specific_copy();}


/// affichage interne d'un Pendule
ostream& Pendule :: affiche (std::ostream& sortie) const {
sortie << "l'angle est: " << parametres << endl;
sortie << "la vitesse angulaire est: "<< derivees << endl;
return sortie;
}

/// renvoie le type d'oscillateur - utilisé dans l'affichage de système pour distinguer les différents oscillateurs
string Pendule:: type () const {
return "Pendule";
}

/// affichage externe d'un Pendule
std::ostream& operator<<(std::ostream& sortie, Pendule const& p) {
return p.affiche(sortie);	
}
