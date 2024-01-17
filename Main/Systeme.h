#include <iostream>
#include <memory>
#include <vector>
#include "Integrateur.h"
#include "Dessinable.h"

#ifndef __SYSTEME_H_INCLUDED__
#define __SYSTEME_H_INCLUDED__

using namespace std;

// - declaration & redefinition

typedef vector <std::unique_ptr<Oscillateur>> Collection;
class Oscillateur;

class Systeme : public Dessinable {

protected:

Integrateur& Inte;
Collection collection;

public:

// - methodes

virtual void dessine() override;
void ajoute_oscillateur (Oscillateur & osc_ptr);
void evolue (double temps);
std::ostream& affiche(std::ostream & sortie) const;

// - constructeurs

Systeme (SupportADessin *support_old, Integrateur& inte);
};

// - operateur externe

std::ostream& operator << (std::ostream& sortie, Systeme const& syst);
#endif
