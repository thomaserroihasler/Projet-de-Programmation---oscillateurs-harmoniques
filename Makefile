CXX = g++
CC  = $(CXX)
# Définit 'g++' comme le compilateur C++.

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences
# Configure les drapeaux du compilateur pour utiliser le standard C++11.

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
CXXFLAGS += -pg                   # pour profiler
LDFLAGS  += -pg                   # pour profiler
CXXFLAGS += -O2                   # pour optimiser la vitesse

all:: testVecteur
# Définit 'testVecteur' comme la cible par défaut.

Constantes.o: Constantes.cc Constantes.h
# Règle pour compiler Constantes.cc.

Vecteur.o: Vecteur.cc Vecteur.h
# Règle pour compiler Vecteur.cc.

testVecteur.o: testVecteur.cc Vecteur.h
# Règle pour compiler testVecteur.cc.

testVecteur: testVecteur.o Vecteur.o
# Règle pour lier 'testVecteur'.

Dessinable.o: Dessinable.cc Dessinable.h
SupportADessin.o: SupportADessin.cc SupportADessin.h
# Règles pour compiler les fichiers relatifs à Dessinable et SupportADessin.

#testOscillateur.o: testOscillateur.cc Oscillateur.h
Oscillateur.o: Oscillateur.cc Oscillateur.h
# Règles pour compiler Oscillateur.

#testOscillateur:  testOscillateur.o Dessinable.o SupportADessin.o Oscillateur.o Vecteur.o Constantes.o 

#testIntegrateur.o: testIntegrateur.cc Integrateur.h
Integrateur.o: Integrateur.cc Integrateur.h
# Règles pour compiler Integrateur.

testIntegrateur: IntegrateurRK4.o testIntegrateur.o Integrateur.o Oscillateur.o Dessinable.o SupportADessin.o Vecteur.o Constantes.o
# Règle pour lier 'testIntegrateur'.

#testRessort.o: testRessort.cc Integrateur.h
#testRessort: testRessort.o Integrateur.o Oscillateur.o Vecteur.o Constantes.o

#testPendule.o: testPendule.cc Integrateur.h
#testPendule: testPendule.o Integrateur.o Oscillateur.o Vecteur.o Constantes.o

Systeme.o: Systeme.h Systeme.cc
TextViewer.o: TextViewer.h TextViewer.cc
Dessinable.o: Dessinable.h Dessinable.cc
Pendule.o: Pendule.h Pendule.cc
Ressort.o: Ressort.h Ressort.cc
Pendule_ressort.o: Pendule_ressort.h Pendule_ressort.cc
Oscillateur_couple.o: Oscillateur_couple.h
Integrateur_Euler.o: Integrateur_Euler.h Integrateur_Euler.cc
Integrateur_New.o: Integrateur_New.h Integrateur_New.cc
Pendule_torssion.o: Pendule_torssion.h Pendule_torssion.cc
Trois_Ressort.o: Trois_Ressort.h Trois_Ressort.cc
IntegrateurRK4.o: IntegrateurRK4.h  IntegrateurRK4.cc
# Règles pour compiler les divers composants.

test_Systeme.o: test_Systeme.cc Integrateur.h Oscillateur.h Dessinable.h SupportADessin.h Vecteur.h Constantes.h Systeme.h TextViewer.h Dessinable.h Pendule.h Ressort.h Pendule_ressort.h Integrateur_Euler.h Integrateur_New.h Pendule_torssion.h Trois_Ressort.h
test_Systeme: test_Systeme.o Integrateur.o Oscillateur.o Dessinable.o SupportADessin.o Vecteur.o Constantes.o Systeme.o TextViewer.o Dessinable.o Pendule.o Ressort.o Pendule_ressort.o Integrateur_Euler.o Integrateur_New.o Pendule_torssion.o Trois_Ressort.o

# Règle pour compiler et lier 'test_Systeme'.

test_New_mark.o: test_New_mark.cc Integrateur.h Oscillateur.h Dessinable.h SupportADessin.h Vecteur.h Constantes.h Systeme.h TextViewer.h Dessinable.h Pendule.h Ressort.h Pendule_ressort.h Integrateur_Euler.h Integrateur_New.h Pendule_torssion.h Trois_Ressort.h
test_New_mark: test_New_mark.o IntegrateurRK4.o Integrateur.o Oscillateur.o Dessinable.o SupportADessin.o Vecteur.o Constantes.o Systeme.o TextViewer.o Dessinable.o Pendule.o Ressort.o Pendule_ressort.o Integrateur_Euler.o Integrateur_New.o Pendule_torssion.o Trois_Ressort.o

# Règle pour compiler et lier 'test_New_mark'.




