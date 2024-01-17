#include "Trois_Ressort.h"

// - constructeurs

Trois_Ressort ::  Trois_Ressort (SupportADessin *support,double x, double y, double x_point, double y_point, double masse_1, double masse_2, double visc, double raid_1,double raid_2, double raid_3)
:Oscillateur_couple (support), axe(1,0,0),const_raideur_1(raid_1), const_raideur_2(raid_2),  const_raideur_3(raid_3),masse_1(masse_1), masse_2(masse_2), viscosite(visc)
{
Vecteur pos(x,y);
Vecteur der(x_point,y_point);
this->set_parametres (pos);
this->set_derivees (der);}


Trois_Ressort :: Trois_Ressort (SupportADessin *support, Vecteur& para, Vecteur& deri)
:Oscillateur_couple (support, para, deri) , axe(1,0,0) /* voir commentaire précédent */ {}


/// méthode "copie" - qui renvoie un pointeur d'allocation dynamique pour la class hétérogène de système

unique_ptr<Trois_Ressort> Trois_Ressort ::specific_copy() const {return unique_ptr<Trois_Ressort>(new Trois_Ressort(*this));}

/// méthode "copie" - qui prend le pointeur Pendule de Torsion de "specific copie" et renvoie un pointeur Oscillateur

unique_ptr <Oscillateur> Trois_Ressort ::general_copy() const {return specific_copy();}

/// desine Triple Ressort
void Trois_Ressort :: dessine()  
{ support->dessine(*this);}

/// equation differentiel du Triple Ressort
Vecteur Trois_Ressort :: equa_diff (double t) {
Vecteur reponse(2);
reponse.set_coord(0,(-1*(((viscosite)/(masse_1))*derivees.valeur(0))+ (-1*((const_raideur_1+const_raideur_3)/(masse_1))*parametres.valeur(0)) +((const_raideur_1)/(masse_1))*parametres.valeur(1)));
reponse.set_coord(1,(-1*(((viscosite)/(masse_2))*derivees.valeur(1))+ (-1*((const_raideur_2+const_raideur_3)/(masse_2))*parametres.valeur(1)) +((const_raideur_3)/(masse_2))*parametres.valeur(0)));
return reponse; 
}

///afichage interne d'un Ressort Triple
ostream& Trois_Ressort :: affiche(std::ostream& sortie) const {
sortie << "la position de la première masse : " << parametres.valeur(0) << " "<<  "la position de la deuxième masse : " << parametres.valeur(1) << endl;
sortie << "la vitesse de la première masse : " << derivees.valeur(0) << " "<<  "la vitesse de la deuxième masse : " << derivees.valeur(1) << endl;
return sortie;
}

string Trois_Ressort:: type () const {
return "Tripple Ressort";
}
