#include "Integrateur_Euler.h"
#include "Ressort.h"
#include <iostream>

///- Ce fichier test ne compile plus car les Ressorts ont été modifiés 
		/*nottament, ils ont plus le(s) même(s) constructeur(s) */

using namespace std;

int main () {
IntegrateurEulerCromer integ (0.01);
Vecteur o (3);
Vecteur axe (0.8,0,0.6);
Ressort res (0.18,0,0.33,0.25,0,0,o,axe);
integ.integre(res, 15.00);
return 0;}

