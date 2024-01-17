#include "Oscillateur.h"

#ifndef __RESSORT_H_INCLUDED__
#define __RESSORT_H_INCLUDED__


class Ressort : public Oscillateur {
private:

double raideur;
double masse;
double longueur;
double frottement;
Vecteur origine;
Vecteur axe;


// - methodes privees

double parametres_axiales () {return (parametres.project_ortho(axe).norme2());}
double derivees_axiales () {return (derivees.project_ortho(axe).norme2());}

protected:
Vecteur equa_diff (double t) override;

public:

unique_ptr <Ressort> specific_copy() const;
virtual unique_ptr <Oscillateur> general_copy() const override;

// - constructeurs

/*Ressort (SupportADessin* const & support,Vecteur origine, Vecteur axe, double position = 1, double vitesse = 0, double raideur = 0, double masse = 1, double longueur =0.5, double frottement = 0)
:Oscillateur (support), origine(origine), axe(axe), raideur(raideur), masse(masse), longueur(longueur), frottement(frottement)
{ Vecteur val(position, true); set_parametres(val); Vecteur val_2(vitesse, true); set_derivees(val_2);}
*/

Ressort (SupportADessin *support, double position = 1, double vitesse = 0, double raideur = 0, double masse = 1, double longueur =0.5, double frottement = 0)
:Oscillateur (support), raideur(raideur), masse(masse), longueur(longueur), frottement(frottement)
{Vecteur ori (3); Vecteur a(0,0,1); Vecteur val(position, true); set_parametres(val); Vecteur val_2(vitesse, true); set_derivees(val_2);set_origine(ori); set_axe(a);}


Ressort (SupportADessin *support, double position, double vitesse, double raideur , double masse, double longueur, double frottement, Vecteur origine, Vecteur axe)
:Oscillateur (support), raideur(raideur), masse(masse), longueur(longueur), frottement(frottement), origine(origine), axe(axe) 
{Vecteur val(position, true); set_parametres(val); Vecteur val_2(vitesse, true); set_derivees(val_2); }

// - methodes

virtual void dessine() override;
std::ostream& affiche(std::ostream & sortie) const override;
std:: string type () const override;

// - seters
void set_raideur(double const& new_raideur) {raideur = new_raideur;}
void set_masse(double const& new_masse) {masse = new_masse;}
void set_longueur(double const& new_longueur) {longueur = new_longueur;}
void set_frottement(double const& new_frottement) {frottement = new_frottement;}
void set_origine (Vecteur const & origines) {origine = origines;}
void set_axe (Vecteur const & axes) {axe = axes;}
// - geters
double get_raideur() {return raideur;}
double get_masse() {return masse;}
double get_longueur() {return longueur;}
double get_frottement() {return frottement;}
Vecteur get_origine () {return origine;}
Vecteur get_axe () {return axe;}

}; 

#endif
