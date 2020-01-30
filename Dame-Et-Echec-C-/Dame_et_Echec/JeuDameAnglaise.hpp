#ifndef JEUDAMEANGLAISE_HPP
#define JEUDAMEANGLAISE_HPP
#include "Jeu.hpp"

class JeuDameAnglaise: public Jeu {
  protected:
  public:
    JeuDameAnglaise();
    virtual bool victoire( std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse);
};
#endif
