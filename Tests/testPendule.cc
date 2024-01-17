#include "Integrateur_Euler.h"
#include "TextViewer.h"
#include "Pendule.h"
#include <iostream>

using namespace std;

///- Ce fichier test ne compile plus car les Pendules ont été modifiés 
	/*nottament, ils ont plus le(s) même(s) constructeur(s) */

int main () {
IntegrateurEulerCromer integ (0.01);
Pendule pend (1.57,0);
integ.integre(pend, 25.00);
return 0;}

