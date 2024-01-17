#include "Oscillateur_couple.h"

#ifndef __PENDULE_RESSORT_H_INCLUDED__
#define  __PENDULE_RESSORT_H_INCLUDED__

class PenduleRessort: public Oscillateur {

private:

// - attributs

Vecteur axe; // axe directeur (Vecteur a dans le complément mathématique)
double masse; 
double longueur_repos;
double const_raideur;


// - methodes privées
protected:
Vecteur equa_diff (double t) override;

public:

// - constructeurs

PenduleRessort (SupportADessin* const & support,double x, double y, double x_point, double y_point,double masse = 1, double longueur = 1, double raid = 1)
:Oscillateur (support), axe(1,0,0), masse (masse), longueur_repos (longueur), const_raideur (raid)
{
Vecteur pos(x,y);
Vecteur der(x_point,y_point);
this->set_parametres (pos);
this->set_derivees (der);
}

PenduleRessort (SupportADessin* const & support, Vecteur& para, Vecteur& deri, double masse = 1, double longueur = 1, double raid = 1)
:Oscillateur (support, para, deri), axe(1,0,0),masse(masse), longueur_repos(longueur), const_raideur(raid) {}

// - Methodes

virtual void dessine() override;
virtual std:: string type const override;
virtual std::ostream& affiche(std::ostream & sortie) const override;

// - seters
void set_raideur(double const& new_raideur) {const_raideur = new_raideur;}
void set_masse(double const& new_masse) {masse = new_masse;}
void set_longueur_repos(double const& new_longueur) {longueur_repos = new_longueur;}
void set_axe (Vecteur const & axes) {axe = axes;}
// - geters
double get_raideur() {return const_raideur;}
double get_masse() {return masse;}
double get_longueur_repos() {return longueur_repos;}
Vecteur get_axe () {return axe;}

}; 


#endif
