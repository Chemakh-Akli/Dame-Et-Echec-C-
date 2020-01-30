#ifndef JEUECHEC_HPP
#define JEUECHEC_HPP
#include "Jeu.hpp"

class JeuEchec: public Jeu {
  protected:
  public:
    JeuEchec();
    virtual bool victoire(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse);
};
#endif