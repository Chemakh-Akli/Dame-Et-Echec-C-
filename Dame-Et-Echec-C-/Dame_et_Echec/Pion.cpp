#include "Pion.hpp"
#include "Dame.hpp"


Pion::Pion(int x, int y , std::string c):PieceDame(x,y,c),role("P"){}

std::string Pion::getRole() const{
  return role;
}

void Pion::promotion(std::vector<Piece*> & joueur_courant, int taille){
    int x1 ;
    int y1;
  if(this->couleur == "blanc" && this->y == taille -1){
    x1 = this->getX();
    y1 = this->getY();
    this->setCoord(11,11);
    Piece* dame = new Dame(x1,y1,"blanc");
    joueur_courant.push_back(dame);

  }
  else{
    if(this->couleur == "noir" && this->y == 0){
      x1 = this->getX();
      y1 = this->getY();
      this->setCoord(11,11);
      Piece* dame = new Dame(x1,y1,"noir");
      joueur_courant.push_back(dame);
    }
  }
}

int Pion::valeurDePrise(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x, int y){
  int hd = 0;
  int hg = 0;
  int bd = 0;
  int bg = 0;
  Piece* bientot_mort;
  if(contains(joueur_adverse,x+1,y+1) && !contains(cimtierre,x+1,y+1) &&  !contains(joueur_adverse,x+2,y+2) && !contains(joueur_courant,x+2,y+2) && x+2 <taille && y+2 < taille ){
    bientot_mort = getPiece(joueur_adverse,x+1,y+1);
    cimtierre.push_back(bientot_mort);
    hd = 1 + valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,x+2,y+2);
  }

  if(contains(joueur_adverse,x-1,y+1)  && !contains(cimtierre,x-1,y+1) && !contains(joueur_adverse,x-2,y+2) && !contains(joueur_courant,x-2,y+2) && x-2 >=0  && y+2 < taille ){
    bientot_mort = getPiece(joueur_adverse,x-1,y+1);
    cimtierre.push_back(bientot_mort);
    hg = 1 + valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,x-2,y+2);
  }

  if(contains(joueur_adverse,x+1,y-1)  && !contains(cimtierre,x+1,y-1) && !contains(joueur_adverse,x+2,y-2) && !contains(joueur_courant,x+2,y-2) && x+2 <taille && y-2 >= 0){
    bientot_mort = getPiece(joueur_adverse,x+1,y-1);
    cimtierre.push_back(bientot_mort);
    bd = 1 + valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,x+2,y-2);
  }

  if(contains(joueur_adverse,x-1,y-1)  && !contains(cimtierre,x-1,y-1) && !contains(joueur_adverse,x-2,y-2) && !contains(joueur_courant,x-2,y-2) && x+2 >= 0 && y-2 >= 0 ){
    bientot_mort = getPiece(joueur_adverse,x-1,y-1);
    cimtierre.push_back(bientot_mort);
    bg = 1 + valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,x-2,y-2);
  }
  std::vector<int> v{hd,hg,bd,bg};
  return max_liste(v);
}


 std::vector<std::pair<int, int>> Pion::mouvementsPossible(int taille, std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse){
  //exemple pour Piece de dames: mouvements en diagonal vers l'avant, sauf dans le cas ou il peut manger
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  std::pair<int,int> d;
  if(this->couleur == "blanc"){
    if(this->x == 0 ){
      if(!contains(joueur_adverse,x+1,y+1) && !contains(joueur_courant,x+1,y+1) && y+1 < taille){
        //std::cout<<"\n" << 2 << std::endl;
        p = std::make_pair(x+1,y+1);
        ListeCoordonnees.push_back(p);
      }
    }
    else{
      if(this->x == taille-1 ){
        if(!contains(joueur_adverse,x-1,y+1) && !contains(joueur_courant,x-1,y+1) && y+1 < taille){
          //std::cout<<"\n" << 3 << std::endl;
          p = std::make_pair(x-1,y+1);
          ListeCoordonnees.push_back(p);
        }
      }
      else{
        //std::cout<<"\n" << 4 << std::endl;
        if(!contains(joueur_adverse,x+1,y+1) && !contains(joueur_courant,x+1,y+1) && y+1 < taille){
          //std::cout<<"\n" << 5 << std::endl;
          p = std::make_pair(x+1,y+1);
          ListeCoordonnees.push_back(p);
        }
        if(!contains(joueur_adverse,x-1,y+1) && !contains(joueur_courant,x-1,y+1) && y+1 < taille){
          //std::cout<<"\n" << 6 << std::endl;
          d = std::make_pair(x-1,y+1);
          ListeCoordonnees.push_back(d);
        }
      }
    }
  }
  else{
    if(this->x == 0 ){
      if( !contains(joueur_adverse,x+1,y-1) && !contains(joueur_courant,x+1,y-1) && y-1 >= 0 ){
        p = std::make_pair(x+1,y-1);
        ListeCoordonnees.push_back(p);
      }
    }
    else{
      if(this->x == taille-1 ){
        if( !contains(joueur_adverse,x-1,y-1) && !contains(joueur_courant,x-1,y-1) && y-1 >= 0){
          p = std::make_pair(x-1,y-1);
          ListeCoordonnees.push_back(p);
        }
      }
      else{
        if(!contains(joueur_adverse,x+1,y-1) && !contains(joueur_courant,x+1,y-1) && y-1 >= 0 ){
          p = std::make_pair(x+1,y-1);
          ListeCoordonnees.push_back(p);
        }
        if(!contains(joueur_adverse,x-1,y-1) && !contains(joueur_courant,x-1,y-1) && y-1 >= 0 ){
          d = std::make_pair(x-1,y-1);
          ListeCoordonnees.push_back(d);
        }
      }
    }
  }
  return ListeCoordonnees;
}


//renvoi liste de position que le Piece peut manger
 std::vector<std::pair<int,int>> Pion::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){
  std::vector<std::pair<int,int>> listMangeable;
  std::pair<int,int> hd;
  std::pair<int,int> hg;
  std::pair<int,int> bd;
  std::pair<int,int> bg;

  if(contains(joueur_adverse,x+1,y+1) && !contains(bientot_mort,x+1,y+1) && !contains(joueur_adverse,x+2,y+2) && !contains(joueur_courant,x+2,y+2) && x+2 <taille && y+2 < taille ){
    hd = std::make_pair(x+1,y+1);
    listMangeable.push_back(hd);
  }

  if(contains(joueur_adverse,x-1,y+1) && !contains(bientot_mort,x-1,y+1) && !contains(joueur_adverse,x-2,y+2) && !contains(joueur_courant,x-2,y+2) && x-2 >=0  && y+2 < taille ){
    hg = std::make_pair(x-1,y+1);
    listMangeable.push_back(hg);
  }

  if(contains(joueur_adverse,x+1,y-1) && !contains(bientot_mort,x+1,y-1) && !contains(joueur_adverse,x+2,y-2) && !contains(joueur_courant,x+2,y-2) && x+2 <taille && y-2 >= 0){
    bd = std::make_pair(x+1,y-1);
    listMangeable.push_back(bd);
  }

  if(contains(joueur_adverse,x-1,y-1) && !contains(bientot_mort,x-1,y-1) && !contains(joueur_adverse,x-2,y-2) && !contains(joueur_courant,x-2,y-2) && x+2 >= 0 && y-2 >= 0 ){
    bg = std::make_pair(x-1,y-1);
    listMangeable.push_back(bg);
  }
  return listMangeable;
}


//return pair of next move position x,y according to the initiale move position
std::pair<int, int> Pion::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){
  std::pair<int, int> nextmove;
  if(x2-this->getX() == 1 && y2-this->getY() == 1){
    //hd
    nextmove.first = this->getX()+2;
    nextmove.second = this->getY()+2;
  }
  else{
    if(x2-this->getX() == -1 && y2-this->getY() == 1){
      //hg
      nextmove.first = this->getX()-2;
      nextmove.second = this->getY()+2;
    }
    else{
      if(x2-this->getX() == 1 && y2- this->getY() == -1){
        //bd
        nextmove.first = this->getX()+2;
        nextmove.second = this->getY()-2;
      }
      else{
        //  if(this->getX()-x2 == -1 && this->getY()-y2 == -1){
        //bg
        nextmove.first = this->getX()-2;
        nextmove.second = this->getY()-2;
      }
    }
  }
  return nextmove;
}

//propose les Pieces mangeable -> choix -> jump -> propose choix tant que les jumps ne sont pas fini
 void Pion::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max){

  std::pair<int,int> res;
  std::vector<std::pair<int,int>> liste_mangeable;
  std::vector<Piece*>  bientot_mort;
  std::pair<int,int> nextPosition;
  int cpt_prise = 0;
  int select;


  while(true){

    liste_mangeable = this->listeMangeable(joueur_courant,joueur_adverse,bientot_mort, taille, x, y);

    if( liste_mangeable.size() == 0){
      if(cpt_prise == rafle_max ){
        break;
      }
      else{
        std::cout << "\nVous pouvez prendre plus de pièce adverse que ça , regardez bien\n" << std::endl;
        cpt_prise = 0;
        x = x_initial;
        y = y_initial;
        bientot_mort.clear();
        this->setCoord(x_initial,y_initial);
        this->jumpRafle(joueur_courant,joueur_adverse,taille,x_initial,y_initial,rafle_max);
      }
    }

    std::cout << "Selectionnez un des choix disponibles en inscrivant la valeur qui leur est associée\n" << std::endl;
    for (int i = 0; i <  liste_mangeable.size(); ++i){
      std::cout << "\nChoix  "<< i<< " : Coordonnees X = " << liste_mangeable.at(i).first << " Coordonnee Y = " <<  liste_mangeable.at(i).second << "\n" <<std::endl;
    }
    std::cin >> select;
    while (std::cin.fail() || select <0 || select >= liste_mangeable.size() ){
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
      std::cin >> select;
    }

    nextPosition = this->nextMove( joueur_courant,joueur_adverse, taille, liste_mangeable.at(select).first, liste_mangeable.at(select).second);

    this->setCoord(  nextPosition.first, nextPosition.second);

    Piece* p = getPiece(joueur_adverse, liste_mangeable.at(select).first,  liste_mangeable.at(select).second);
    bientot_mort.push_back(p);
    cpt_prise++;

  }
  for(int i = 0 ; i < bientot_mort.size() ; i++){
    //joueur_adverse.erase(std::remove(joueur_adverse.begin(), joueur_adverse.end(),  bientot_mort.at(i)), joueur_adverse.end());
    bientot_mort.at(i)->setCoord(-1,-1);
  }
}

void Pion::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max){

  std::pair<int,int> res;
  std::vector<std::pair<int,int>> liste_mangeable;
  std::vector<Piece*>  bientot_mort;
  std::pair<int,int> nextPosition;
  int cpt_prise = 0;
  int select;


  while(true){
    std::cout << "start while"<<std::endl;
    liste_mangeable = this->listeMangeable(joueur_courant,joueur_adverse,bientot_mort, taille, x, y);
    std::cout << "init liste_mangeable"<<std::endl;
    if(liste_mangeable.size() == 0){
      std::cout << "liste_mangeable == 0"<<std::endl;
      if(cpt_prise == rafle_max ){
        break;
      }
      else{
        std::cout << "\nVous pouvez prendre plus de pièce adverse que ça , regardez bien\n" << std::endl;
        cpt_prise = 0;
        x = x_initial;
        y = y_initial;
        bientot_mort.clear();
        this->setCoord(x_initial,y_initial);
        this->jumpRafleBot(joueur_courant,joueur_adverse,taille,x_initial,y_initial,rafle_max);

      }
    }

    std::cout << "Selectionnez un des choix disponibles en inscrivant la valeur qui leur est associée\n" << std::endl;
    for (int i = 0; i <  liste_mangeable.size(); ++i){
      std::cout << "\nChoix  "<< i<< " : Coordonnees X = " << liste_mangeable.at(i).first << " Coordonnee Y = " <<  liste_mangeable.at(i).second << "\n" <<std::endl;
    }
    if(liste_mangeable.size() == 1)
      select = 0;
    if(liste_mangeable.size() > 1){
     select = rand() % liste_mangeable.size();
    }

    nextPosition =  this->nextMove( joueur_courant,joueur_adverse, taille, liste_mangeable.at(select).first, liste_mangeable.at(select).second);

    this->setCoord(  nextPosition.first, nextPosition.second);

    Piece* p = getPiece(joueur_adverse, liste_mangeable.at(select).first,  liste_mangeable.at(select).second);
    bientot_mort.push_back(p);
    cpt_prise++;

  }
  for(int i = 0 ; i < bientot_mort.size() ; i++){
    //joueur_adverse.erase(std::remove(joueur_adverse.begin(), joueur_adverse.end(),  bientot_mort.at(i)), joueur_adverse.end());
    bientot_mort.at(i)->setCoord(-1,-1);
  }
}
