#include "SupportADessin.h"
// Inclut le fichier d'en-tête "SupportADessin.h".

#ifndef __DESSINABLE_H_INCLUDED__
#define __DESSINABLE_H_INCLUDED__
// Vérifie si le fichier "Dessinable.h" n'a pas été inclus précédemment.

class Dessinable {
    // Définit une classe abstraite "Dessinable".

protected:	
    SupportADessin *support;
    // Pointeur vers un objet de type SupportADessin.

public:
    void set_support (SupportADessin *new_sup) {
        support = new_sup;
    }
    // Définit le support de dessin.

    Dessinable (SupportADessin* support_old): support(support_old) {}
    // Constructeur qui initialise le support de dessin.

    virtual ~Dessinable () { support = nullptr; }
    // Destructeur qui met le pointeur de support à nullptr.

    virtual void dessine() = 0;
    // Méthode virtuelle pure à implémenter dans les sous-classes.

private:
};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
