#include "Vecteur.h"
#include <iostream>

 ///- Ce fichier test compile encore car les vecteurs n'ont pas été modifiés 
		/*Par contre, ceci est la dernière version du testVecteur
		 *La première n'existe plus car après le "refactoring" de code, il était recommandé de réécrire le fichier (Semaine 4 - P4) */
 
using namespace std;

int main () {

// un vecteur en 3D :
Vecteur vect1(5);

// un autre vecteur en 3D
Vecteur vect2(2.6, 3.5,  4.1);
/*	
Vecteur vect3(vect1);  // copie de V1
Vecteur vect4(4);      // le vecteur nul en 4D

vect1 = vect2;

Vecteur Vect5;

cout << "Vecteur 1 : " << vect1;
cout << "Vecteur 2 : " << vect2;
cout << "Vecteur 5 : " << Vect5;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1 != vect3) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;*/

return 0;
}
