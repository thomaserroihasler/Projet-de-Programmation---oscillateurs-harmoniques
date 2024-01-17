#include "SupportADessin.h"
#include <iostream>

#ifndef __TEXTVIEWER_H_INCLUDED__
#define __TEXTVIEWER_H_INCLUDED__

class TextViewer : public SupportADessin {

public:

TextViewer(std::ostream& sortie)
            : sortie (sortie){}
            
virtual ~ TextViewer() override  {}

	void dessine(Pendule const& pend) override;
	void dessine(Ressort const& ress) override;
	void dessine(Oscillateur const& oscil)override;
	void dessine(Systeme const& oscil)override;
	
protected:

private:
std:: ostream & sortie;
};

#endif
