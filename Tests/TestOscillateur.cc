#include "TextViewer.h"
#include "Oscillateur.h"
#include "Constantes.h"
#include <iostream>
#include <vector>

///- Ce fichier test ne compile plus car les Oscillateurs ont été modifiés 
	/*Ils ont plus le(s) même(s) constructeur(s)
	 *Oscillateur est une classe abstraite et donc peut pas être déclarée
		* Oscillateur n'a plus une definition pour equa_diff */

using namespace std;

int main () {
Vecteur para (1.0,2.0);
Vecteur vite (3.0,4.0);
Vecteur para_2 (-2.0,-1.0);
Vecteur vite_2 (-6.0,-12.0);
Oscillateur r (para,vite);
cout << r.get_parametres() << endl;
cout << r.get_derivees() << endl;
r.set_parametres(para_2);
cout << r.get_parametres() << endl;
r.set_derivees(para_2);
cout << r.get_derivees() << endl;
return 0;}
