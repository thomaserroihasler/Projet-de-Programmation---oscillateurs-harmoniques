#include <string>
#include <vector>

#ifndef __VECTEUR_H_INCLUDED__
#define __VECTEUR_H_INCLUDED__

typedef std::vector <double> coordonnees;

class Vecteur {

private:

coordonnees coordonnee;
unsigned int dimension;


public:

// - constructeurs


Vecteur (double valeur, bool trivial): dimension(1) {coordonnee.push_back(valeur);}

Vecteur (unsigned int dim = 1): dimension(dim)
{	for (unsigned int i (0); i < dim; ++i) 
		{coordonnee.push_back(0);}}

Vecteur (double x, double y, double z):  dimension(3)
{	coordonnee.push_back(x); 
	coordonnee.push_back(y); 
	coordonnee.push_back(z);}

Vecteur (double x, double y): dimension(2)
{	coordonnee.push_back(x);
	coordonnee.push_back(y);}
	
Vecteur(std::vector<double> vect): coordonnee(vect),  dimension(vect.size()) {}

Vecteur (double a, double b, double c, double d):  dimension(4)
{	coordonnee.push_back(a); 
	coordonnee.push_back(b); 
	coordonnee.push_back(c);
	coordonnee.push_back(d);
	}



// - méthodes

void augmente (double valeur_ajoute = 0.0) {coordonnee.push_back(valeur_ajoute); ++dimension;}

void set_coord (size_t placement, double valeur = 0) {coordonnee[placement] = valeur;}

double valeur (size_t position = 0) const {return coordonnee[position];}

unsigned int return_dim () const { return dimension;}

double norme2 () const;

double norme () const;

Vecteur vect_uni () const;

Vecteur project_ortho (Vecteur & autre);

std::string plonge_dim (Vecteur & deuxieme);

// - opérateurs internes

std::ostream& affiche (std::ostream &) const;

bool operator == (Vecteur& comparaison) const; 

bool operator != (Vecteur& comparaison) const;

Vecteur operator * (Vecteur& autre);

Vecteur operator * (double& scalaire);
/*{
	Vecteur reponse(coordonnee.size());
	reponse.coordonnee.clear();
	for (size_t i (0); i < coordonnee.size() ; ++i) 
		{reponse.coordonnee.push_back(scalaire * coordonnee[i]);}
	return reponse;}*/

double operator ^ (Vecteur const & deuxieme) const;

void operator += (Vecteur const& autre);
	/*{if (dimension == autre.dimension) {
		for (size_t i(0); i < dimension; ++i) {
			coordonnee[i] += autre.coordonnee[i];}}
	else {cerr<< "Attention ! Une addition de vecteurs de dimensions différentes a été tentée... opération annulée";}}*/

void operator *= (double& scalaire);
/*{
		for (size_t i(0); i < dimension; ++i) {
			coordonnee[i] *= scalaire;}}*/

void operator -= (Vecteur& autre);

Vecteur operator - ();
};

// - opérateurs externes 

Vecteur operator * (double scalaire, Vecteur vecteur);
/*{
	Vecteur reponse(vecteur);
	reponse *= scalaire;
	return reponse;}*/
	
std::ostream& operator << (std::ostream& sortie, Vecteur const& affiche);

Vecteur operator + (Vecteur premier, Vecteur const& autre) {
premier += autre;
return premier;}


///****************************  fonctions obsolètes  *********************************

/*Vecteur (Vecteur& copie)
: dimension(copie.dimension), nom (copie.nom + " copie")
{ for (size_t i (0); i < copie.coordonnee.size(); ++i) { coordonnee.push_back(copie.coordonnee[i]);}}*/

//void operator = (Vecteur& autre); 

#endif
