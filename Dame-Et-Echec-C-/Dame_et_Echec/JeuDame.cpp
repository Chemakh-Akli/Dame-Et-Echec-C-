#include "JeuDame.hpp"

JeuDame::JeuDame():Jeu(){
  taille = 10;
  int y(0);
  for(int i = 0;i < taille ; i++){
    Piece* a = new Pion(i,y,"blanc");
    Piece* b = new Pion(i,y+2,"blanc");
    Piece* c = new Pion(i,y+6,"noir");
    Piece* d = new Pion(i,y+8,"noir");
    un.push_back(a);
    un.push_back(b);
    deux.push_back(c);
    deux.push_back(d);
    if(i%2 == 0){
      y++;
    }
    else{
      y--;
    }
  }
}

bool JeuDame::victoire(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse){
  int j1 = Piece::piecesSorties(joueur_courant);
  if( j1 == 20 ){
    std::cout <<"\n" + joueur_adverse.at(0)->getCouleur() + " a gagné\n" << std::endl;
    return true;
  }
  else{
    return false;
  }
}
