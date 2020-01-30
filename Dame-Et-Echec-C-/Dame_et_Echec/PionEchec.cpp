#include "PionEchec.hpp"
#include "Reine.hpp"



PionEchec::PionEchec(int x, int y , std::string c):PieceEchec(x,y,c),role("P"){}

int PionEchec::valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y){}

std::vector<std::pair<int,int>>  PionEchec::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){}

std::pair<int, int>  PionEchec::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){}

void  PionEchec::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max){}

void PionEchec::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) {}

std::string PionEchec::getRole() const{
  return role;
}

void PionEchec::promotion(std::vector<Piece*> & joueur_courant, int taille){
  int x1 ;
  int y1;
  if(this->couleur == "blanc" && this->y == taille -1){
    x1 = this->getX();
    y1 = this->getY();
    this->setCoord(11,11);
    Piece* dame = new Reine(x1,y1,"blanc");
    joueur_courant.push_back(dame);

  }
  else{
    if(this->couleur == "noir" && this->y == 0){
      x1 = this->getX();
      y1 = this->getY();
      this->setCoord(11,11);
      Piece* dame = new Reine(x1,y1,"noir");
      joueur_courant.push_back(dame);
    }
  }
}

std::vector<std::pair<int, int>> PionEchec::mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse){
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  std::pair<int,int> d;
  if(this->couleur == "noir"){
    //std::cout<<"\n" << 1 << std::endl;
    if(!contains(joueur_adverse,x,y+1) && !contains(joueur_courant,x,y+1) && y+1 < taille){
      p = std::make_pair(x,y+1);
      ListeCoordonnees.push_back(p);
    }
    if(!this->a_deja_bouge && !contains(joueur_adverse,x,y+2) && !contains(joueur_courant,x,y+2)){
      p = std::make_pair(x,y+2);
      ListeCoordonnees.push_back(p);
    }
    if(contains(joueur_adverse,x+1,y+1)){
      p = std::make_pair(x+1,y+1);
      ListeCoordonnees.push_back(p);
    }
    if(contains(joueur_adverse,x-1,y+1)){
      p = std::make_pair(x-1,y+1);
      ListeCoordonnees.push_back(p);
    }
  }
  else{
    if(!contains(joueur_adverse,x,y-1) && !contains(joueur_courant,x,y-1) && y-1 >= 0){
      p = std::make_pair(x,y-1);
      ListeCoordonnees.push_back(p);
    }
    if(!this->a_deja_bouge && !contains(joueur_adverse,x,y-2) && !contains(joueur_courant,x,y-2)){
      p = std::make_pair(x,y-2);
      ListeCoordonnees.push_back(p);
    }
    if(contains(joueur_adverse,x+1,y-1)){
      p = std::make_pair(x+1,y-1);
      ListeCoordonnees.push_back(p);
    }
    if(contains(joueur_adverse,x-1,y-1)){
      p = std::make_pair(x-1,y-1);
      ListeCoordonnees.push_back(p);
    }
  }
  return ListeCoordonnees;
}
