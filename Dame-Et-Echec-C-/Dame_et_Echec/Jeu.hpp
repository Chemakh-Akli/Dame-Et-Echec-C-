#ifndef JEU_HPP
#define JEU_HPP
#include <iostream>
#include <string>
#include <vector>

#include "Pion.hpp"
#include "PionAnglaise.hpp"
#include "DameAnglaise.hpp"
#include "Dame.hpp"
#include "PionEchec.hpp"
#include "Chevalier.hpp"
#include "Tour.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
#include "Roi.hpp"



class Jeu{
  protected:
    int taille;
    std::vector<Piece*> un;
    std::vector<Piece*> deux;
  public:
    Jeu();
    int getSize();
    std::vector<Piece*> getPJ1();
    std::vector<Piece*> getPJ2();
    bool coordonneeValide(std::vector<Piece*> joueur_courant ,std::vector<Piece*> joueur_adverse,int x, int y);
    static void affiche(std::vector<Piece*> joueur_courant ,std::vector<Piece*> joueur_adverse,int taille);
    void affichageJoueurs(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse);
    static void afficheListePiece(std::vector<Piece*> joueur_courant);

    virtual bool victoire(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse) = 0;
};
#endif
