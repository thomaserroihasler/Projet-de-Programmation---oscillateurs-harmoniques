#include "Integrateur_Euler.h"
#include "IntegrateurRK4.h"
#include "Oscillateur.h"
#include "Ressort.h"
#include "TextViewer.h"
#include <iostream>
#include <memory>


///- Ce fichier test ne compile plus car les Oscillateurs ont été modifiés 
	/*Ils ont plus le(s) même(s) constructeur(s)
	 *Oscillateur est une classe abstraite et donc peut pas être déclarée
		* Oscillateur n'a plus une definition pour equa_diff */

using namespace std;

int main () {
Vecteur para (0.0,1.0);
Vecteur vite (1.0,2.0);
TextViewer yeeee (cout);
//Oscillateur osc(para, vite);
Ressort lol (&yeeee, 1,1,1,1,1,1,1,1);
//IntegrateurNewmark New (0.01, 0.000001);
IntegrateurRK4 hihi(0.01);
hihi.integre(lol,0.65);
//New.integre(lol,0.65);
cout << lol;


return 0;}
