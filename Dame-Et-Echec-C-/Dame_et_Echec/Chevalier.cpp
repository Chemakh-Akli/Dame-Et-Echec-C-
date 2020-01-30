#include "Chevalier.hpp"



Chevalier::Chevalier(int x, int y , std::string c):PieceEchec(x,y,c),role("C"){}

int Chevalier::valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y){}

std::vector<std::pair<int,int>>  Chevalier::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){}

std::pair<int, int>  Chevalier::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){}

void  Chevalier::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max){}

void Chevalier::promotion(std::vector<Piece*> & joueur_courant, int taille){}

std::string Chevalier::getRole() const{
  return role;
}

void Chevalier::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) {}

std::vector<std::pair<int, int>> Chevalier::mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse){
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  std::pair<int,int> d;
    //std::cout<<"\n" << 1 << std::endl;
    if(!contains(joueur_courant,x+1,y+2) && y+2 < taille && x+1 < taille ){
      p = std::make_pair(x+1,y+2);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-1,y+2) && y+2 < taille && x-1 >= 0){
      p = std::make_pair(x-1,y+2);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+1,y-2) && y-2 >= 0 && x+1 < taille){
      p = std::make_pair(x+1,y-2);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-1,y-2) && y-2 >= 0 && x-1 >= 0){
      p = std::make_pair(x-1,y-2);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+2,y+1) && y+1 < taille && x+2 < taille ){
      p = std::make_pair(x+2,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+2,y-1) && y-1 >= 0 && x+2 < taille ){
      p = std::make_pair(x+2,y-1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-2,y+1) && y+1 < taille && x-2 >= 0){
      p = std::make_pair(x-2,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-2,y-1) && y-1 >= 0 && x-2 >= 0){
      p = std::make_pair(x-2,y-1);
      ListeCoordonnees.push_back(p);
    }

  return ListeCoordonnees;
}
