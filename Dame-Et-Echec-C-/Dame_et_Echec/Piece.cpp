#include "Piece.hpp"

Piece::Piece(int x,int y,std::string c):x(x),y(y),couleur(c),a_deja_bouge(false){}

int Piece::getX() const{
  return x;
}

int Piece::getY() const{
  return y;
}

bool Piece::getADejaBouge() const{
  return a_deja_bouge;
}

void Piece::setADejaBouge(bool a){
  a_deja_bouge = a;
}

std::string Piece::getCouleur() const{
  return couleur;
}

void Piece::setCoord(int x1,int y1){
  this->x = x1;
  this->y = y1;
}

Piece* Piece::getPiece(std::vector<Piece*>  joueur_courant, int x1,int y1){
  for(int i = 0; i < joueur_courant.size(); i++){
    if(joueur_courant.at(i)->getX() == x1 && joueur_courant.at(i)->getY() == y1){
      return joueur_courant.at(i);
    }
  }
  return NULL;
}

bool Piece::contains(std::vector<Piece*> joueur_courant, int x1,int y1){
  for(int i = 0; i < joueur_courant.size(); i++){
    if(joueur_courant.at(i)->getX() == x1 && joueur_courant.at(i)->getY() == y1){
      return true;
    }
  }
  return false;
}

int Piece::piecesSorties(std::vector<Piece*>  joueur_courant){
  int cpt = 0;
  for(int i = 0; i < joueur_courant.size(); i++){
    if(joueur_courant.at(i)->getX() == -1 && joueur_courant.at(i)->getY() == -1){
      cpt++;
    }
  }
  return cpt;
}

int Piece::max_liste(std::vector<int> a){
  int res = 0;
  for(int i = 0; i < a.size() ; i++){
    if(a.at(i) > res){
      res = a.at(i);
    }
  }
  return res;
}

int Piece::max(std::vector<std::pair<Piece*, int>> a){
  int res = 0;
  for(int i = 0; i < a.size() ; i++){
    if(a.at(i).second > res){
      res = a.at(i).second;
    }
  }
  return res;
}

std::vector< std::pair<Piece*,int> >  Piece::prisePossible(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse ,int taille){

  std::vector< std::pair<Piece*,int> > res;
  std::vector< std::pair<Piece*,int> > aux;
  std::pair<Piece*,int> a;
  std::vector<Piece*> clone_courant ;
  std::vector<Piece*> clone_adverse ;
  std::vector<Piece*> cimtierre;
  int rafle;

  for(int i = 0 ; i< joueur_courant.size() ; i++){
    int x = joueur_courant.at(i)->getX();
    int y = joueur_courant.at(i)->getY();
    clone_courant = joueur_courant;
    clone_adverse = joueur_adverse;
    if(joueur_courant.at(i)->getX() >= 0 && joueur_courant.at(i)->getX() < taille && joueur_courant.at(i)->getY() >= 0 && joueur_courant.at(i)->getY() < taille ){
      rafle = joueur_courant.at(i)->valeurDePrise(clone_courant,clone_adverse,cimtierre,taille,x,y);
      if(rafle > 0){
        a = std::make_pair(joueur_courant.at(i),rafle);
        res.push_back(a);
      }
      cimtierre.clear();
    }
  }
  int best_rafle = max(res);
  for(int j = 0 ; j < res.size() ; j++){
    if(res.at(j).second == best_rafle){
      aux.push_back(res.at(j));
    }
  }
  return aux; // res;
}
