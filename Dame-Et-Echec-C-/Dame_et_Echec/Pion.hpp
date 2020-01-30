#ifndef PION_HPP
#define PION_HPP
#include "PieceDame.hpp"

class Pion: public PieceDame {
  protected:
  std::string role;
  public:
    Pion(int x,int y,std::string c);

    virtual void promotion(std::vector<Piece*> & joueur_courant , int taille);
    virtual std::string getRole() const;
    virtual int valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y);
    virtual std::pair<int, int> nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2) ;
    virtual void jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max) ;
    virtual std::vector<std::pair<int,int>> listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y) ;
    virtual void jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) ;
    virtual std::vector<std::pair<int, int>> mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse);
};
#endif
