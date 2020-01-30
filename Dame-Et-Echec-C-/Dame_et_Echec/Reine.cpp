#include "Reine.hpp"



Reine::Reine(int x, int y , std::string c):PieceEchec(x,y,c),role("D"){}

int Reine::valeurDePrise(std::vector<Piece*> & joueur_courant,std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x ,int y){}

std::vector<std::pair<int,int>>  Reine::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){}

std::pair<int, int>  Reine::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){}

void  Reine::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille ,int x_initial, int y_initial , int rafle_max){}

void Reine::promotion(std::vector<Piece*> & joueur_courant, int taille){}

void Reine::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max) {}

std::string Reine::getRole() const{
  return role;
}



std::vector<std::pair<int, int>> Reine::mouvementsPossible(int taille,std::vector<Piece*> joueur_courant,std::vector<Piece*> joueur_adverse){
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  std::pair<int,int> d;

  int i = this->getX();
  int j = this->getY();

  while(i + 1  < taille && j + 1 < taille  && !contains(joueur_courant,i+1,j+1)){
    //std::cout<< "\n1" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i+1,j+1)){
      p = std::make_pair(i+1,j+1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i+1,j+1);
    ListeCoordonnees.push_back(p);
    i++;
    j++;
  }

  i = this->getX();
  j = this->getY();

  while(i - 1  >= 0 && j + 1 < taille  && !contains(joueur_courant,i-1,j+1)){
    //std::cout<< "\n2" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i-1,j+1)){
      p = std::make_pair(i-1,j+1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i-1,j+1);
    ListeCoordonnees.push_back(p);
    i--;
    j++;
  }

  i = this->getX();
  j = this->getY();

  while(i + 1  < taille && j - 1 >= 0 && !contains(joueur_courant,i+1,j-1)){
    //std::cout<< "\n3" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i+1,j-1)){
      p = std::make_pair(i+1,j-1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i+1,j-1);
    ListeCoordonnees.push_back(p);
    i++;
    j--;
  }

  i = this->getX();
  j = this->getY();

  while(i - 1  >= 0 && j - 1 >= 0  && !contains(joueur_courant,i-1,j-1)){
    //std::cout<< "\n4" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i-1,j-1)){
      p = std::make_pair(i-1,j-1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i-1,j-1);
    ListeCoordonnees.push_back(p);
    i--;
    j--;
  }

  i = this->getX();
  j = this->getY();

  while( j + 1 < taille  && !contains(joueur_courant,i,j+1)){
    //std::cout<< "\n1" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i,j+1)){
      p = std::make_pair(i,j+1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i,j+1);
    ListeCoordonnees.push_back(p);
    j++;
  }

  i = this->getX();
  j = this->getY();

  while(j - 1 >= 0  && !contains(joueur_courant,i,j-1)){
    //std::cout<< "\n2" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i,j-1)){
      p = std::make_pair(i,j-1);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i,j-1);
    ListeCoordonnees.push_back(p);
    j--;
  }

  i = this->getX();
  j = this->getY();

  while(i + 1  < taille  && !contains(joueur_courant,i+1,j)){
    //std::cout<< "\n3" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i+1,j)){
      p = std::make_pair(i+1,j);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i+1,j);
    ListeCoordonnees.push_back(p);
    i++;
  }

  i = this->getX();
  j = this->getY();

  while(i - 1  >= 0  && !contains(joueur_courant,i-1,j)){
    //std::cout<< "\n4" <<" " << i << " "<< j << std::endl;
    if(contains(joueur_adverse,i-1,j)){
      p = std::make_pair(i-1,j);
      ListeCoordonnees.push_back(p);
      break;
    }
    p = std::make_pair(i-1,j);
    ListeCoordonnees.push_back(p);
    i--;
  }

  return ListeCoordonnees;
}
