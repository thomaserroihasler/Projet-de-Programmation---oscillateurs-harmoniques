#include "Oscillateur_couple.h"


#ifndef __TROIS_RESSORT_H_INCLUDED__
#define  __TROIS_RESSORT_H_INCLUDED__

class Trois_Ressort: public Oscillateur_couple {

private:

// - attributs

Vecteur axe; // axe directeur (Vecteur a dans le complément mathématique)
double const_raideur_1;
double const_raideur_2;
double const_raideur_3;
double masse_1;
double masse_2;
double viscosite;


// - methodes privées

protected:
Vecteur equa_diff (double t) override;

public:

// - constructeurs

Trois_Ressort (SupportADessin *support,double x, double y, double x_point, double y_point, double masse_1, double masse_2, double visc, double raid_1,double raid_2, double raid_3);
Trois_Ressort (SupportADessin *support, Vecteur& para, Vecteur& deri);

// - Methodes

virtual void dessine() override;
std::ostream& affiche(std::ostream & sortie) const override; 
std::string type() const override; 
unique_ptr <Trois_Ressort> specific_copy() const;
virtual unique_ptr <Oscillateur> general_copy() const override;

// - seters
void set_const_raideur_1(double const& new_const) {const_raideur_1 = new_const;}
void set_const_raideur_2(double const& new_const) {const_raideur_2 = new_const;}
void set_const_raideur_3(double const& new_const) {const_raideur_3 = new_const;}
void set_masse_1(double const& m) {masse_1 = m;}
void set_masse_2(double const& m) {masse_2 = m;}
void set_viscosite(double const& v) {viscosite = v;}
void set_axe (Vecteur const & axes) {axe = axes;}
// - geters
double get_const_raideur_1(double const& new_const) {return const_raideur_1;}
double get_const_raideur_2(double const& new_const) {return const_raideur_2;}
double get_const_raideur_3(double const& new_const) {return const_raideur_3;}
double get_masse_1() {return masse_1;}
double get_masse_2() {return masse_2;}
double get_viscosite() {return viscosite;}
Vecteur get_axe () {return axe;}

};

#endif
