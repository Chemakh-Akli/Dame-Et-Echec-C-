#ifndef PIECEDAME_HPP
#define PIECEDAME_HPP
#include "Piece.hpp"

class PieceDame: public Piece {
  protected:
  public:
    PieceDame(int x, int y , std::string couleur);

    virtual std::string getRole() const = 0;
    virtual void promotion(std::vector<Piece*> & joueur_courant , int taille) =0;
    virtual int valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y) = 0;
    virtual std::vector<std::pair<int,int>> listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y) = 0; // A REDEFINIR
    virtual std::pair<int, int> nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2) = 0; // A REDEFINIR
    virtual void jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max) = 0; // A REDEFINIR
    virtual void jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) = 0;  
    virtual std::vector<std::pair<int, int>> mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse) = 0; //A REDEFINIR
};
#endif
