#include "Oscillateur_couple.h"

#ifndef __PENDULE_RESSORT_H_INCLUDED__
#define  __PENDULE_RESSORT_H_INCLUDED__
// Vérifie si le fichier d'en-tête "Pendule_Ressort.h" a déjà été inclus.

class Pendule_Ressort: public Oscillateur {
    // Définit la classe Pendule_Ressort, une spécialisation de la classe Oscillateur.

private:
    // Attributs privés
    Vecteur axe; // axe directeur, correspond au vecteur 'a' dans le complément mathématique.
    double masse; 
    double longueur_repos;
    double const_raideur;

protected:
    Vecteur equa_diff (double t) override;
    // Implémente l'équation différentielle spécifique au pendule à ressort.

public:
    // Constructeurs
    Pendule_Ressort (SupportADessin *support, double x, double y, double x_point, double y_point, double masse = 1, double longueur = 1, double raid = 1)
    : Oscillateur(support), axe(1, 0, 0), masse(masse), longueur_repos(longueur), const_raideur(raid) {
        Vecteur pos(x, y);
        Vecteur der(x_point, y_point);
        this->set_parametres(pos);
        this->set_derivees(der);
    }
    // Constructeur initialisant les attributs avec des valeurs spécifiques.

    Pendule_Ressort (SupportADessin *support, Vecteur& para, Vecteur& deri, double masse = 1, double longueur = 1, double raid = 1)
    : Oscillateur(support, para, deri), axe(1, 0, 0), masse(masse), longueur_repos(longueur), const_raideur(raid) {}
    // Constructeur initialisant avec des vecteurs de paramètres et dérivées spécifiques.

    // Méthodes
    virtual void dessine() override;
    virtual std::ostream& affiche(std::ostream & sortie) const override;
    virtual std::string type () const override;
    unique_ptr<Pendule_Ressort> specific_copy() const;
    virtual unique_ptr<Oscillateur> general_copy() const override;
    // Méthodes pour le dessin, l'affichage, la copie et obtenir le type.

    // Setters
    void set_raideur(double const& new_raideur) { const_raideur = new_raideur; }
    void set_masse(double const& new_masse) { masse = new_masse; }
    void set_longueur_repos(double const& new_longueur) { longueur_repos = new_longueur; }
    void set_axe(Vecteur const & axes) { axe = axes; }

    // Getters
    double get_raideur() { return const_raideur; }
    double get_masse() { return masse; }
    double get_longueur_repos() { return longueur_repos; }
    Vecteur get_axe() { return axe; }

};

#endif
// Fin de la condition de prévention de l'inclusion multiple.
