#include "Jeu.hpp"


Jeu::Jeu(){}

int Jeu::getSize(){
  return taille;
}


std::vector<Piece*>  Jeu::getPJ1(){
  return un;
}


std::vector<Piece*>  Jeu::getPJ2(){
  return deux;
}

bool Jeu::coordonneeValide(std::vector<Piece*> joueur_courant ,std::vector<Piece*> joueur_adverse, int x1, int y1){
/*  if(x1 == -10 && y1 == -10){
    return false;
  }*/
  if( x1 < 0 || x1 >= this->getSize()  || y1 < 0 || y1 >= this->getSize()  ){
    std::cout << "coordonnées hors du terrain\n" << std::endl;
    return false;
  }
  else{
    for(int i = 0 ; i < joueur_courant.size() ; i++){
      if(joueur_courant.at(i)->getX() == x1 && joueur_courant.at(i)->getY() == y1){
        std::cout << "Coordonnées valides\n" << std::endl;
        return true;
      }
    }
    for(int i = 0 ; i < joueur_adverse.size() ; i++){
      if(joueur_adverse.at(i)->getX() == x1 && joueur_adverse.at(i)->getY() == y1){
        std::cout << "Cette emplacement est occupé par un Piece adverse\n" << std::endl;
        return false;
      }
    }
    std::cout << "Cette emplacement est vide\n" << std::endl;
    return false;
  }
}



void Jeu::affiche(std::vector<Piece*> joueur_courant ,std::vector<Piece*> joueur_adverse,int taille){
  std::cout << "\nEtat du plateau\n";
  for (int j = 0; j < taille +1; ++j){
    std::cout <<"\n";
    for (int i= 0; i < taille +1; ++i){
      if(i==0){
        if (j==0){
          std::cout << "X  ";
        }
        else{
          std::cout << j-1 <<" ";
          if(j== taille +1){
            std::cout <<"\n";
          }
        }
      }
      else{
        if (j==0){
          std::cout << i-1<< "  ";
        }
        else{
          Piece* p = Piece::getPiece(joueur_courant,i-1,j-1);
          if(p != NULL){
            std::cout << p->getRole()+"W ";
            if(j== taille +1){
              std::cout <<"\n";
            }
          }
          else{
            Piece* d = Piece::getPiece(joueur_adverse,i-1,j-1);
            if(d != NULL){
              std::cout << d->getRole()+"B ";
              if(j== taille +1){
                std::cout <<"\n";
              }
            }
            else{
              std::cout << " . ";
              if(j== taille +1){
                std::cout <<"\n";
              }
            }
          }
        }
      }
    }
  }
}



void Jeu::afficheListePiece(std::vector<Piece*> joueur_courant){
  for(int i = 0 ; i < joueur_courant.size() ; i++){
    std::cout << joueur_courant.at(i)->getRole() + " :"<<  joueur_courant.at(i)->getX() <<"  "<< joueur_courant.at(i)->getY() << std::endl;
  }
}


void Jeu::affichageJoueurs(std::vector<Piece*> joueur_courant ,std::vector<Piece*> joueur_adverse ){
    std::cout << "Vos Pieces : " << std::endl;
    Jeu::afficheListePiece(joueur_courant);
    std::cout << "\nPieces adverses : " << std::endl;
    Jeu::afficheListePiece(joueur_adverse);
}
