#include "Trois_Ressort.h"
#include "Pendule.h"
#include "Integrateur_Euler.h"
#include "Systeme.h"
#include "TextViewer.h"
#include "Ressort.h"
#include <cmath>
#include <memory>
#include <iostream>

using namespace std;

int main () {	
IntegrateurEulerCromer heyhe;
TextViewer hey(cout);
cout << "yo" << endl;
Systeme Thom (&hey, heyhe);
Ressort kek (&hey, 1,0,2,2,2,2);
Pendule Kim (&hey, 1,0,1,2,1,1);
heyhe.integre(Kim,0.1);
cout << Kim << endl;
Thom.ajoute_oscillateur (kek);
Thom.ajoute_oscillateur (Kim);
Thom.dessine();
for (int time (9); time < 10; ++time) {
//Thom.evolue(0.1);
}
Thom.dessine();

return 0;}
