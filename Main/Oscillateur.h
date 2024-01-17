#include "Vecteur.h"
#include "Dessinable.h"
#include <iostream>
#include <vector>
#include <string>

#ifndef __OSCILLATEUR_H_INCLUDED__
#define __OSCILLATEUR_H_INCLUDED__
// Vérifie si le fichier d'en-tête "Oscillateur.h" a déjà été inclus.

class SupportADessin;

class Oscillateur: public Dessinable {
    // Définit la classe Oscillateur qui hérite de Dessinable.

protected:
    Vecteur parametres; // position, angle ...
    Vecteur derivees; // vitesse, vitesse angulaire ...
    virtual Vecteur equa_diff (double t) = 0; // Équation différentielle virtuelle pure.

public:
    // - Constructeurs
    Oscillateur (SupportADessin *support)
    : Dessinable (support) {
        Vecteur origine (0,0,0);
        parametres = origine;
        derivees = origine;
    }
    // Constructeur par défaut initialisant les paramètres et dérivées à l'origine.

    Oscillateur (SupportADessin *support, Vecteur& parametres, Vecteur& derivees)
    : Dessinable(support), parametres(parametres), derivees(derivees) {}
    // Constructeur initialisant l'oscillateur avec des paramètres et dérivées spécifiques.

    // - Méthodes
    virtual std::ostream& affiche(std::ostream & sortie) const;
    // Méthode virtuelle pour afficher l'oscillateur.

    virtual std::string type () const = 0;
    // Méthode virtuelle pure retournant le type de l'oscillateur.

    virtual unique_ptr <Oscillateur> general_copy() const /*= 0*/;
    // Méthode virtuelle pour copier l'oscillateur.

    Vecteur get_equa_diff (double t) { return equa_diff(t); }
    // Renvoie le résultat de l'équation différentielle.

    Vecteur get_parametres() const { return parametres; }
    Vecteur get_derivees() const { return derivees; }
    // Accesseurs pour les paramètres et dérivées.

    void set_parametres (Vecteur& new_param) { parametres = new_param; }
    void set_derivees (Vecteur& new_der) { derivees = new_der; }
    void set_parametres_val (Vecteur new_param) { parametres = new_param; }
    void set_derivees_val (Vecteur new_der) { derivees = new_der; }
    // Mutateurs pour les paramètres et dérivées.

    void dessine() override;
    // Méthode pour dessiner l'oscillateur.

};


// - Opérateurs externes

std::ostream& operator << (std::ostream& sortie, Oscillateur const& oscil);
// Surcharge de l'opérateur '<<' pour l'affichage.

#endif
// Fin de la condition de prévention de l'inclusion multiple.
