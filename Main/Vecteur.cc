#include "Vecteur.h"
#include <cmath>
#include <iostream>

using namespace std;

// - opérateurs
	
	
/// affichage
ostream& Vecteur :: affiche (ostream& sortie) const 
{	for (size_t i(0); i < coordonnee.size(); ++i)
			{sortie << coordonnee[i] << " ";}
	return sortie;}


/// comparateur (égalité) 	
bool Vecteur :: operator == (Vecteur& comparaison) const 
{	bool reponse = false;
		if (dimension == comparaison.dimension) {reponse = true;
		for (size_t i (0); i < coordonnee.size(); ++i) 
			{ if ( coordonnee[i] != comparaison.coordonnee[i])	{return false;}}}
return reponse;}																				


/// comparateur (inégalité)
bool Vecteur :: operator != (Vecteur& comparaison) const {bool reponse = true;
if (*this == comparaison) {reponse = false;} return true;}



/// produit scalaire
double Vecteur :: operator ^ (Vecteur const & deuxieme) const
{	if (dimension != deuxieme.return_dim()) {
cerr << "Attention ! Produit scalaire de deux vecteurs de dimensions différentes. 0 a été renvoyé " << endl;
return 0;}

	double reponse (0);
		for (size_t i(0); i < coordonnee.size(); ++i) 
		{reponse += coordonnee[i] * deuxieme.coordonnee[i];}
		return reponse;}


/// vecteur opposé (-1*v)
Vecteur Vecteur :: operator - ()
{Vecteur reponse;
	for (size_t i(0); i < coordonnee.size(); ++i) 
		{reponse.coordonnee.push_back(-1 * coordonnee[i]);}
	return reponse;
	}


/// multiplication d'un vecteur par un scalaire (même vecteur)
void Vecteur :: operator *= (double & scalaire) {
		for (size_t i(0); i < dimension; ++i) {
			coordonnee[i] *= scalaire;}}




/// addition de vecteur (même vecteur)
void Vecteur :: operator += (Vecteur const& autre ){
	if (dimension == autre.dimension) {
		for (size_t i(0); i < dimension; ++i) {
			coordonnee[i] += autre.coordonnee[i];}}
	else {cerr<< "Attention ! Une addition de vecteurs de dimensions différentes a été tentée... opération annulée";}}




/// soustraction de vecteur (même vecteur)
void Vecteur :: operator -= (Vecteur& autre) {
	if (dimension == autre.dimension) {
		for (size_t i(0); i < dimension; ++i) {
			coordonnee[i] -= autre.coordonnee[i];}}
	else {cerr<< "Attention ! Une soustraction de vecteurs de dimensions differentes a été tentée... opération annulée";}}



/// produit vectoriel (uniquement 3D)
Vecteur Vecteur :: operator * (Vecteur& autre) {
	Vecteur reponse(3);
	if ((dimension == autre.dimension) and (dimension == 3)) {
		reponse.coordonnee[0] = coordonnee[1]*autre.coordonnee[2]-coordonnee[2]*autre.coordonnee[1];
		reponse.coordonnee[1] = coordonnee[2]*autre.coordonnee[0]-coordonnee[0]*autre.coordonnee[2];
		reponse.coordonnee[2] = coordonnee[0]*autre.coordonnee[1]-coordonnee[1]*autre.coordonnee[0];}	
	else {
	cerr<< "Attention ! Produit vectoriel impossible! Le vecteur nul a été renvoyé comme réponse";} 
	// renvoie un vecteur nul en cas de différence de dimension
	return reponse;}


/// multiplication d'un vecteur par un scalaire (nouveau vecteur)
Vecteur Vecteur :: operator * (double& scalaire) {
	Vecteur reponse(coordonnee.size());
	reponse.coordonnee.clear();
	for (size_t i (0); i < coordonnee.size() ; ++i) 
		{reponse.coordonnee.push_back(scalaire * coordonnee[i]);}
	return reponse;}


// - methodes


/// norme vectorielle (au carré)
double Vecteur :: norme2 () const {
	double reponse (0);
	for (size_t i (0); i < coordonnee.size(); ++i) 
		{reponse += coordonnee[i] * coordonnee[i]; }return reponse;}


/// norme vectorielle
double Vecteur :: norme () const {
	double reponse = sqrt(norme2());
	return reponse;}
	
	
	
/// vecteur unitaire	
Vecteur Vecteur :: vect_uni() const {
Vecteur answer(*this);
double yo (1/(answer.norme()));
return answer * yo;
}	


/// projection orthogonale
Vecteur Vecteur :: project_ortho(Vecteur & axe) {
return ((*this^axe)/axe.norme2()) * axe;}	

/*
/// plongement dimensionnel 
std::string Vecteur :: plonge_dim (Vecteur & deuxieme) // renvoie le nom du vecteur qui est plongé
{if (dimension > deuxieme.dimension) {
	for (unsigned int i(deuxieme.dimension); i < dimension; ++i) 
			{deuxieme.coordonnee.push_back(0); ++deuxieme.dimension;} return deuxieme.nom;} // ajoute des 0 au dimensions supplémentaires
else {
	for (unsigned int i(dimension); i < deuxieme.dimension; ++i) 
			{coordonnee.push_back(0); ++deuxieme.dimension;} return nom;}}
*/
// fonctions

/// multiplication d'un vecteur par un scalaire (nouveau vecteur) (scalaire à gauche)
Vecteur operator * (double scalaire, Vecteur vecteur) {
	Vecteur reponse(vecteur);
	reponse *= scalaire;
	return reponse;}

/// affichage externe (syntaxe conventionnelle)
ostream& operator << (std::ostream& sortie, Vecteur const& vec) {
return (vec.affiche(sortie));}

/// addition de vecteurs

