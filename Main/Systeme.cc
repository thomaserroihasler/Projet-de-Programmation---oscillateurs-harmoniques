#include "Integrateur.h"
#include "Systeme.h"

Systeme :: Systeme	(SupportADessin *support_old, Integrateur&/* * */ inte)
: Dessinable(support_old), Inte (inte) //integrateur(std::unique_ptr<Integrateur>(inte))
{ /*inte = nullptr; support_old = nullptr;*/}


void Systeme::evolue(double temps) {
	for (auto & oscil : collection) {
		Inte.integre(*oscil, temps);
	}}

void Systeme:: ajoute_oscillateur (Oscillateur & osc_ptr) {
osc_ptr.set_support(support);
collection.push_back(osc_ptr.general_copy());}

///affichage interne d'un Systeme
std::ostream& Systeme :: affiche(std::ostream & sortie) const {
for (size_t i (0); i < collection.size(); ++i){ 
sortie << "Oscillateur " << i + 1 << ": "<< (*(collection[i])).type() << endl << *(collection[i]) << endl;}
return sortie;}

void Systeme :: dessine()  
{ support->dessine(*this);
}

///affichage externe (utilise l'affichage interne)
std::ostream& operator << (std::ostream& sortie, Systeme const&  syst) {
return (syst.affiche(sortie));}
