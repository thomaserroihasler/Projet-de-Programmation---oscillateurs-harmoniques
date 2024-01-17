#include "Pendule_ressort.h"

/// méthode "copie" - qui renvoie un pointeur d'allocation dynamique pour la class hétérogène de système

unique_ptr<Pendule_Ressort> Pendule_Ressort ::specific_copy() const {return unique_ptr<Pendule_Ressort>(new Pendule_Ressort(*this));}

/// méthode "copie" - qui prend le pointeur Pendule de Torsion de "specific copie" et renvoie un pointeur Oscillateur

unique_ptr <Oscillateur> Pendule_Ressort ::general_copy() const {return specific_copy();}

/// desine Pendule Ressort
void Pendule_Ressort :: dessine()  
{ support->dessine(*this);}

/// equation differentiel du Pendule Ressort
Vecteur Pendule_Ressort :: equa_diff (double t) {
Vecteur g (0,9.81); // peut pas utiliser la constante g car g est 3D (de plus on le veut possitif sur l'axe y)
return g + -((const_raideur/masse)*(1-((longueur_repos)/(parametres.norme())))*parametres);
}

std::ostream& Pendule_Ressort :: affiche(std::ostream & sortie) const {
sortie << "la position est: " << parametres << endl;
sortie << "la vitesse est: " << derivees << endl;
return sortie;	
}

/// renvoie le type d'oscillateur - utilisé dans l'affichage de systeme pour distinguer les differents oscillateurs
string Pendule_Ressort:: type () const {
return "Pendule Ressort";
}
