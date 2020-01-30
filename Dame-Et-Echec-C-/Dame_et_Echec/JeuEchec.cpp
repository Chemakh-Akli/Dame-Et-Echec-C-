#include "JeuEchec.hpp"

JeuEchec::JeuEchec():Jeu(){
  taille = 8;
  int y(0);
  for(int i = 0;i < taille ; i++){
    Piece* c = new PionEchec(i,6,"blanc");
    Piece* d = new PionEchec(i,1,"noir");
    un.push_back(c);
    deux.push_back(d);
  }
  Piece* a = new Tour(0,7,"blanc");
  Piece* b = new Tour(0,0,"noir");
  un.push_back(a);
  deux.push_back(b);

  Piece* a2 = new Tour(7,7,"blanc");
  Piece* b2 = new Tour(7,0,"noir");
  un.push_back(a2);
  deux.push_back(b2);

  Piece* e = new Chevalier(1,7,"blanc");
  Piece* f = new Chevalier(1,0,"noir");
  un.push_back(e);
  deux.push_back(f);

  Piece* e2 = new Chevalier(6,7,"blanc");
  Piece* f2 = new Chevalier(6,0,"noir");
  un.push_back(e2);
  deux.push_back(f2);

  Piece* g = new Fou(2,7,"blanc");
  Piece* h = new Fou(2,0,"noir");
  un.push_back(g);
  deux.push_back(h);

  Piece* g2 = new Fou(5,7,"blanc");
  Piece* h2 = new Fou(5,0,"noir");
  un.push_back(g2);
  deux.push_back(h2);

  Piece* j = new Reine(3,7,"blanc");
  Piece* k = new Reine(3,0,"noir");
  un.push_back(j);
  deux.push_back(k);

  Piece* m = new Roi(4,7,"blanc");
  Piece* n = new Roi(4,0,"noir");
  un.push_back(m);
  deux.push_back(n);


}

bool JeuEchec::victoire(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse){ //ECHEC ET MAT PAS IMPLEMENTE
  int j1 = Piece::piecesSorties(joueur_courant);
  if(j1 == 20 ){
    std::cout <<"\n" + joueur_adverse.at(0)->getCouleur() + " a gagné\n" << std::endl;
    return true;
  }
  else{
    return false;
  }
}
