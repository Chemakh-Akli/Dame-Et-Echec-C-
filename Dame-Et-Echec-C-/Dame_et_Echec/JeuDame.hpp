#ifndef JEUDAME_HPP
#define JEUDAME_HPP
#include "Jeu.hpp"

class JeuDame: public Jeu {
  protected:
  public:
    JeuDame();
    virtual bool victoire( std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse);
};
#endif