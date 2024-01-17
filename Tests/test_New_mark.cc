#include "Integrateur_New.h"
#include "IntegrateurRK4.h"
#include "Integrateur_Euler.h"
#include "TextViewer.h"
#include "Ressort.h"
#include <iostream>


using namespace std;

int main () {
IntegrateurRK4 hiy (0.01);
IntegrateurNewmark hey (0.01, 0.00001);
IntegrateurEulerCromer hoy (0.01);
TextViewer lol(cout);
//SupportADessin* hihi (&lol);
TextViewer ye(cout);
TextViewer yoy(cout);
//SupportADessin* hihe (&ye);
Ressort testii (&yoy, 10,1,1,1,0.1,1);
Ressort testi (&ye, 10,1,1,1,0.1,1);
Ressort test (&lol, 10,1,1,1,1,1);
hiy.integre (testii, 100);
hey.integre (testi, 100);
hoy.integre (test, 100);
cout << testi << endl;
cout << testii << endl;
return 0;
}
