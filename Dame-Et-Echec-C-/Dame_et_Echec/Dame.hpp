#ifndef DAME_HPP
#define DAME_HPP
#include "PieceDame.hpp"
#include <tuple>

class Dame: public PieceDame {
  protected:
  std::string role;
  public:
    Dame(int x,int y,std::string c);

    virtual std::string getRole() const;
    virtual void promotion(std::vector<Piece*> & joueur_courant , int taille) ;
    virtual int valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y);
    virtual std::pair<int, int> nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2) ;
    virtual void jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max) ;
    virtual std::vector<std::pair<int,int>> listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y) ;
    virtual std::vector<std::pair<int, int>> mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse);
    virtual void jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max);
};
#endif
