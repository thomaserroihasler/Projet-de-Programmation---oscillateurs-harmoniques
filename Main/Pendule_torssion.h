#include "Oscillateur.h"

#ifndef __PENDULE_TORSSION_H_INCLUDED__
#define __PENDULE_TORSSION_H_INCLUDED__
// Vérifie si le fichier d'en-tête "Pendule_de_Torsion.h" a déjà été inclus.

class Pendule_de_Torsion : public Oscillateur {
    // Définit la classe Pendule_de_Torsion qui hérite de Oscillateur.

private:
    double coef_torsion;	
    double inertie;
    double frottement;
    Vecteur origine;

protected:
    Vecteur equa_diff (double t) override;
    // Implémente l'équation différentielle spécifique au pendule de torsion.

public:
    unique_ptr<Pendule_de_Torsion> specific_copy() const;
    virtual unique_ptr<Oscillateur> general_copy() const override;
    // Méthodes pour réaliser une copie de l'objet.

    // Constructeurs
    Pendule_de_Torsion (SupportADessin *support, double angle, double vitesse_ang, double coef_torsion, double inertie, double frottement, Vecteur origine)
    : Oscillateur(support), coef_torsion(coef_torsion), inertie(inertie), frottement(frottement), origine(origine) {
        Vecteur val(angle, true); 
        set_parametres(val); 
        Vecteur val_2(vitesse_ang, true); 
        set_derivees(val_2); 
    }
    // Initialise le pendule de torsion avec des valeurs spécifiques pour l'angle, la vitesse angulaire, etc.

    // Méthodes
    virtual void dessine() override;
    virtual std::ostream& affiche(std::ostream & sortie) const override; 
    virtual std::string type () const override;
    // Méthodes pour le dessin, l'affichage et obtenir le type de l'oscillateur.

    // Setters
    void set_coef_torsion(double const& new_coef) { coef_torsion = new_coef; }
    void set_inertie(double const& new_inertie) { inertie = new_inertie; }
    void set_frottement(double const& new_frottement) { frottement = new_frottement; }
    void set_origine (Vecteur origine) { origine = origine; }
    // Méthodes pour définir les attributs du pendule de torsion.
};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
