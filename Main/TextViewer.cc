#include "TextViewer.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Oscillateur.h"
#include "Systeme.h"
#include <iostream>
using namespace std;

void TextViewer:: dessine (Pendule const& pend) 
{sortie << pend << endl;}

void TextViewer:: dessine (Ressort const& ress) 
{sortie << ress << endl;}

void TextViewer:: dessine (Oscillateur const& oscil) 
{sortie << oscil << endl;}

void TextViewer:: dessine (Systeme const& syst)
{sortie << syst << endl;}
