#ifndef PIECE_HPP
#define PIECE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Piece {
  protected:
    int x;
    int y;
    std::string couleur;
    bool a_deja_bouge;
  public:
    Piece(int x,int y,std::string couleur);
    int getX() const;
    int getY() const;
    std::string getCouleur() const;
    bool getADejaBouge() const;
    void setADejaBouge(bool a);
    void setCoord(int x,int y);
    static Piece* getPiece(std::vector<Piece*>  joueur_courant, int x,int y);
    static bool contains(std::vector<Piece*> joueur_courant, int x,int y);
    static int piecesSorties(std::vector<Piece*>  joueur_courant);
    int max_liste(std::vector<int> a);
    static int max(std::vector< std::pair<Piece *, int> >  a);
    static std::vector< std::pair<Piece *, int> > prisePossible(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse,int taille);

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
