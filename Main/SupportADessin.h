#include <iostream>

#ifndef __SUPPORTADESSIN_H_INCLUDED__
#define __SUPPORTADESSIN_H_INCLUDED__

using namespace std;

class Pendule;
class Ressort;
class Oscillateur;
class Systeme;

class SupportADessin{
 public:

virtual ~SupportADessin() {}

  virtual void dessine(Pendule const& pend) = 0;
  virtual void dessine(Ressort const& ress) = 0;
  virtual void dessine (Oscillateur const& oscil) = 0;
  virtual void dessine(Systeme  const& syst) = 0;
};
#endif
