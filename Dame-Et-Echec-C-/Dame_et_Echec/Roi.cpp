#include "Roi.hpp"



Roi::Roi(int x, int y , std::string c):PieceEchec(x,y,c),role("R"){}

int Roi::valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y){}

std::vector<std::pair<int,int>>  Roi::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){}

std::pair<int, int>  Roi::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){}

void  Roi::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max){}

void Roi::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) {}

void Roi::promotion(std::vector<Piece*> & joueur_courant, int taille){}

std::string Roi::getRole() const{
  return role;
}



std::vector<std::pair<int, int>> Roi::mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse){
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  std::pair<int,int> d;
    //std::cout<<"\n" << 1 << std::endl;
    if(!contains(joueur_courant,x,y+1) && y+1 < taille ){
      p = std::make_pair(x,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+1,y+1) && y+1 < taille && x+1 < taille){
      p = std::make_pair(x+1,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-1,y+1) && y+1 < taille && x-1 >= 0){
      p = std::make_pair(x-1,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-1,y) && x-1 >= 0){
      p = std::make_pair(x-1,y);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+1,y)  && x+1 < taille ){
      p = std::make_pair(x+1,y);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x,y-1) && y-1 >= 0 ){
      p = std::make_pair(x,y-1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x+1,y-1) && y-1 >= 0 && x+1 < taille){
      p = std::make_pair(x-2,y+1);
      ListeCoordonnees.push_back(p);
    }

    if(!contains(joueur_courant,x-1,y-1) && y-1 >= 0 && x-1 >= 0){
      p = std::make_pair(x-1,y-1);
      ListeCoordonnees.push_back(p);
    }

  return ListeCoordonnees;
}
