#include "JeuDameAnglaise.hpp"

JeuDameAnglaise::JeuDameAnglaise():Jeu(){
  taille = 8;

  for(int i = 0;i < taille ; i++){
    if(i%2 == 0){
      Piece* a = new PionAnglaise(i,0,"blanc");
      Piece* c = new PionAnglaise(i,2,"blanc");
      Piece* d = new PionAnglaise(i,6,"noir");

      un.push_back(a);
      un.push_back(c);
      deux.push_back(d);
    }
    else{
      Piece* a = new PionAnglaise(i,1,"blanc");
      Piece* c = new PionAnglaise(i,5,"noir");
      Piece* d = new PionAnglaise(i,7,"noir");
      un.push_back(a);
      deux.push_back(c);
      deux.push_back(d);
    }
  }
}

bool JeuDameAnglaise::victoire(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse){
  int j1 = Piece::piecesSorties(joueur_courant);
  if( j1 == 12){
    std::cout <<"\n" + joueur_adverse.at(0)->getCouleur() + " a gagné\n" << std::endl;
    return true;
  }
  else{
    return false;
  }
}
