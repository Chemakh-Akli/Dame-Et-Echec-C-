#include "Dame.hpp"


Dame::Dame(int x, int y , std::string c):PieceDame(x,y,c),role("D"){}

std::string Dame::getRole() const{
  return role;
}

void Dame::promotion(std::vector<Piece*> & joueur_courant , int taille){

}

int Dame::valeurDePrise(std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse, std::vector<Piece*> & cimtierre,int taille,int x, int y){
  int hd = 0;
  int hg = 0;
  int bd = 0;
  int bg = 0;
  int hd_max = 0;
  int hg_max = 0;
  int bd_max = 0;
  int bg_max = 0;

  bool a_deja_mange = false;
  bool vient_de_mange = false;

  Piece* bientot_mort;
  //std::cout<<"\n" << 0 << std::endl;

  int i = x;
  int j = y;

  while(i + 1  < taille && j+ 1 < taille){
    //std::cout<<"\n" << 1 << std::endl;
    if(contains(joueur_courant,i+1,j+1)){
      //std::cout<<"\n" << 2 << std::endl;
      break;
    }
    if(contains(joueur_adverse,i+1,j+1)  &&  !contains(joueur_adverse,i+2,j+2) && !contains(joueur_courant,i+2,j+2) && i+2 < taille && j+2 < taille ){
      //std::cout<<"\n" << 3 << std::endl;
      if(contains(cimtierre,i+1,j+1)){
        break;
      }
      else{
        bientot_mort = getPiece(joueur_adverse,i+1,j+1);
        cimtierre.push_back(bientot_mort);
        i+=2;
        j+=2;
        a_deja_mange = true;
        vient_de_mange = true;
      }
    }
    if(a_deja_mange){
      if(vient_de_mange){
        hd = 1 +  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(hd > hd_max){
          hd_max = hd;
        }
      }
      else{
        hd =  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(hd > hd_max){
          hd_max = hd;
        }
      }
    }
    vient_de_mange = false;
    i++;
    j++;
  }



  i = x;
  j = y;
  a_deja_mange = false;
  vient_de_mange = false;



  while(i - 1 >= 0 && j + 1 < taille){
    if(contains(joueur_courant,i-1,j+1)){
      break;
    }
    if(contains(joueur_adverse,i-1,j+1)  &&  !contains(joueur_adverse,i-2,j+2) && !contains(joueur_courant,i-2,j+2) && i-2 >= 0 && j+2 < taille ){
      if(contains(cimtierre,i-1,j+1)){
        break;
      }
      else{
        bientot_mort = getPiece(joueur_adverse,i-1,j+1);
        cimtierre.push_back(bientot_mort);
        i-=2;
        j+=2;
        a_deja_mange = true;
        vient_de_mange = true;
      }
    }
    if(a_deja_mange){
      if(vient_de_mange){
        hg = 1 +  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(hg > hg_max){
          hg_max = hg;
        }
      }
      else{
        hg =  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(hg > hg_max){
          hg_max = hg;
        }
      }
    }
    vient_de_mange = false;
    i--;
    j++;
  }


  i = x;
  j = y;
  a_deja_mange = false;
  vient_de_mange = false;


  while(i - 1  >= 0 && j - 1 >= 0){
    if(contains(joueur_courant,i-1,j-1)){
      break;
    }
    if(contains(joueur_adverse,i-1,j-1)  &&  !contains(joueur_adverse,i-2,j-2) && !contains(joueur_courant,i-2,j-2) && i-2 >= 0 && j-2 >= 0 ){
      if(contains(cimtierre,i-1,j-1)){
        break;
      }
      else{
        bientot_mort = getPiece(joueur_adverse,i-1,j-1);
        cimtierre.push_back(bientot_mort);
        i-=2;
        j-=2;
        a_deja_mange = true;
        vient_de_mange = true;
      }
    }
    if(a_deja_mange){
      if(vient_de_mange){
        bg = 1 +  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(bg > bg_max){
          bg_max = bg;
        }
      }
      else{
        bg =  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(bg > bg_max){
          bg_max = bg;
        }
      }
    }
    vient_de_mange = false;
    i--;
    j--;
  }


  i = x;
  j = y;
  a_deja_mange = false;
  vient_de_mange = false;


  while(i + 1 < taille && j - 1 >= 0){
    if(contains(joueur_courant,i+1,j-1)){
      break;
    }
    if(contains(joueur_adverse,i+1,j-1)  &&  !contains(joueur_adverse,i+2,j-2) && !contains(joueur_courant,i+2,j-2) && i+2 < taille && j-2 >= 0 ){
      if(contains(cimtierre,i+1,j-1)){
        break;
      }
      else{
        bientot_mort = getPiece(joueur_adverse,i+1,j-1);
        cimtierre.push_back(bientot_mort);
        i+=2;
        j-=2;
        a_deja_mange = true;
        vient_de_mange = true;
      }
    }
    if(a_deja_mange){
      if(vient_de_mange){
        bd = 1 +  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(bd > bd_max){
          bd_max = bd;
        }
      }
      else{
        bd =  valeurDePrise(joueur_courant,joueur_adverse,cimtierre,taille,i,j);
        if(bd > bd_max){
          bd_max = bd;
        }
      }
    }
    vient_de_mange = false;
    i++;
    j--;
  }
  std::vector<int> v{hd_max,hg_max,bd_max,bg_max};
  return max_liste(v);

}



 std::vector<std::pair<int, int>> Dame::mouvementsPossible(int taille, std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse){
  //exemple pour Piece de dames: mouvements en diagonal vers l'avant, sauf dans le cas ou il peut manger
  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int,int> p;
  int i = this->getX();
  int j = this->getY();

  while(i + 1  < taille && j + 1 < taille &&  !contains(joueur_adverse,i+1,j+1) && !contains(joueur_courant,i+1,j+1)){
    //std::cout<< "\n1" <<" " << i << " "<< j << std::endl;
    p = std::make_pair(i+1,j+1);
    ListeCoordonnees.push_back(p);
    i++;
    j++;
  }

  i = this->getX();
  j = this->getY();

  while(i - 1  >= 0 && j + 1 < taille &&  !contains(joueur_adverse,i-1,j+1) && !contains(joueur_courant,i-1,j+1)){
    //std::cout<< "\n2" <<" " << i << " "<< j << std::endl;
    p = std::make_pair(i-1,j+1);
    ListeCoordonnees.push_back(p);
    i--;
    j++;
  }

  i = this->getX();
  j = this->getY();

  while(i + 1  < taille && j - 1 >= 0 &&  !contains(joueur_adverse,i+1,j-1) && !contains(joueur_courant,i+1,j-1)){
    //std::cout<< "\n3" <<" " << i << " "<< j << std::endl;
    p = std::make_pair(i+1,j-1);
    ListeCoordonnees.push_back(p);
    i++;
    j--;
  }

  i = this->getX();
  j = this->getY();

  while(i - 1  >= 0 && j - 1 >= 0 &&  !contains(joueur_adverse,i-1,j-1) && !contains(joueur_courant,i-1,j-1)){
    //std::cout<< "\n4" <<" " << i << " "<< j << std::endl;
    p = std::make_pair(i-1,j-1);
    ListeCoordonnees.push_back(p);
    i--;
    j--;
  }


  return ListeCoordonnees;
}


//renvoi liste de position que le Piece peut manger
 std::vector<std::pair<int,int>> Dame::listeMangeable(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, std::vector<Piece*> & bientot_mort,int taille,int x, int y){
  std::vector<std::pair<int,int>> listMangeable;
  std::pair<int,int> p;

  int i = x;
  int j = y;

  while( i + 1  < taille && j + 1 < taille ){
    if(contains(joueur_adverse,i+1,j+1)  &&  /* !contains(bientot_mort,i+1,j+1) && */ !contains(joueur_adverse,i+2,j+2) && !contains(joueur_courant,i+2,j+2) && i+2 < taille && j+2 < taille ){
      if(contains(bientot_mort,i+1,j+1)){
        //return listMangeable;
        break;
      }
      p = std::make_pair(i+1,j+1);
      listMangeable.push_back(p);
      break;
    }
    i++;
    j++;
  }

  i = x;
  j = y;

  while( i - 1  >= 0 && j + 1 < taille ){
    if(contains(joueur_adverse,i-1,j+1)  &&  !contains(joueur_adverse,i-2,j+2) && !contains(joueur_courant,i-2,j+2) && i-2 >= 0 && j+2 < taille){
      if(contains(bientot_mort,i-1,j+1)){        
        break;
      }
      p = std::make_pair(i-1,j+1);
      listMangeable.push_back(p);
      break;
    }
    i--;
    j++;
  }

  i = x;
  j = y;

  while( i + 1  < taille && j - 1 >= 0 ){
    if(contains(joueur_adverse,i+1,j-1) &&  !contains(joueur_adverse,i+2,j-2) && !contains(joueur_courant,i+2,j-2) && i+2 < taille && j-2 >= 0){
      if(contains(bientot_mort,i+1,j-1)){
        break;
      }
      p = std::make_pair(i+1,j-1);
      listMangeable.push_back(p);
      break;
    }
    i++;
    j--;
  }

  i = x;
  j = y;

  while( i - 1  >= 0 && j - 1 >= 0  ){
    if( contains(joueur_adverse,i-1,j-1)  &&  !contains(joueur_adverse,i-2,j-2) && !contains(joueur_courant,i-2,j-2) && i-2 >= 0 && j-2 >= 0 ){
      if(contains(bientot_mort,i-1,j-1)){
        //return listMangeable;
        break;
      }
      p = std::make_pair(i-1,j-1);
      listMangeable.push_back(p);
      break;
    }
    i--;
    j--;
  }
  return listMangeable;
}


//return pair of next move position x,y according to the initiale move position
std::pair<int, int> Dame::nextMove(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse,int taille,int x2, int y2){

  std::vector<std::pair<int, int>> ListeCoordonnees;
  std::pair<int, int> p;
  int select;
  int i;
  int j;

  if(x2-this->getX() > 0  && y2-this->getY() > 0){
    //hd
    i = x2 ;
    j = y2 ;

    while(i + 1  < taille && j + 1 < taille &&  !contains(joueur_adverse,i+1,j+1) && !contains(joueur_courant,i+1,j+1)){
      p = std::make_pair(i+1,j+1);
      ListeCoordonnees.push_back(p);
      i++;
      j++;
    }
    std::cout << "Choisissez votre case d'atterissage\n" << std::endl;
    for (int q = 0; q <  ListeCoordonnees.size(); ++q){
      std::cout << "\nChoix  "<< q<< " : Coordonnees X = " << ListeCoordonnees.at(q).first << " Coordonnee Y = " <<  ListeCoordonnees.at(q).second << "\n" <<std::endl;
    }
    std::cin >> select;
    while (std::cin.fail() || select < 0 || select >= ListeCoordonnees.size() ){
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
      std::cin >> select;
    }

    p.first = ListeCoordonnees.at(select).first;
    p.second = ListeCoordonnees.at(select).second;
  }
  else{
    if(x2-this->getX() < 0 && y2-this->getY() > 0){
      //hg
      i = x2 ;
      j = y2 ;

      while(i - 1 >= 0 && j + 1 < taille &&  !contains(joueur_adverse,i-1,j+1) && !contains(joueur_courant,i-1,j+1)){
        p = std::make_pair(i-1,j+1);
        ListeCoordonnees.push_back(p);
        i--;
        j++;
      }
      std::cout << "Choisissez votre case d'atterissage\n" << std::endl;
      for (int q = 0; q <  ListeCoordonnees.size(); ++q){
        std::cout << "\nChoix  "<< q<< " : Coordonnees X = " << ListeCoordonnees.at(q).first << " Coordonnee Y = " <<  ListeCoordonnees.at(q).second << "\n" <<std::endl;
      }
      std::cin >> select;
      while (std::cin.fail() || select < 0 || select >= ListeCoordonnees.size() ){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
        std::cin >> select;
      }

      p.first = ListeCoordonnees.at(select).first;
      p.second = ListeCoordonnees.at(select).second;
    }
    else{
      if(x2-this->getX() > 0 && y2- this->getY() < 0){
        //hd
        i = x2 ;
        j = y2 ;

        while(i+1  < taille  && j - 1 >= 0 &&  !contains(joueur_adverse,i+1,j-1) && !contains(joueur_courant,i+1,j-1)){
          p = std::make_pair(i+1,j-1);
          ListeCoordonnees.push_back(p);
          i++;
          j--;
        }
        std::cout << "Choisissez votre case d'atterissage\n" << std::endl;
        for (int q = 0; q <  ListeCoordonnees.size(); ++q){
          std::cout << "\nChoix  "<< q << " : Coordonnees X = " << ListeCoordonnees.at(q).first << " Coordonnee Y = " <<  ListeCoordonnees.at(q).second << "\n" <<std::endl;
        }
        std::cin >> select;
        while (std::cin.fail() || select <0 || select >= ListeCoordonnees.size() ){
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
          std::cin >> select;
        }

        p.first = ListeCoordonnees.at(select).first;
        p.second = ListeCoordonnees.at(select).second;
      }
      else{
        //  if(this->getX()-x2 == -1 && this->getY()-y2 == -1){
        //bg
        i = x2 ;
        j = y2 ;

        while(i-1  >= 0  && j - 1 >= 0 &&  !contains(joueur_adverse,i-1,j-1) && !contains(joueur_courant,i-1,j-1)){
          p = std::make_pair(i-1,j-1);
          ListeCoordonnees.push_back(p);
          i--;
          j--;
        }
        std::cout << "Choisissez votre case d'atterissage\n" << std::endl;
        for (int q = 0; q <  ListeCoordonnees.size(); ++q){
          std::cout << "\nChoix  "<< q << " : Coordonnees X = " << ListeCoordonnees.at(q).first << " Coordonnee Y = " <<  ListeCoordonnees.at(q).second << "\n" <<std::endl;
        }
        std::cin >> select;
        while (std::cin.fail() || select < 0 || select >= ListeCoordonnees.size() ){
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
          std::cin >> select;
        }

        p.first = ListeCoordonnees.at(select).first;
        p.second = ListeCoordonnees.at(select).second;
      }
    }
  }
  return p;
}

//propose les Pieces mangeable -> choix -> jump -> propose choix tant que les jumps ne sont pas fini
void Dame::jumpRafle(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max){

  std::pair<int,int> res;
  std::vector<std::pair<int,int>> liste_mangeable;
  std::vector<Piece*>  bientot_mort;
  std::pair<int,int> nextPosition;
  int cpt_prise = 0;
  int select;


  while(true){

    liste_mangeable = this->listeMangeable(joueur_courant,joueur_adverse,bientot_mort, taille, x, y);

    std::cout << "\nPiece mangeable : " << liste_mangeable.size()  <<std::endl;
    std::cout << "\nPiece mangeable : " << cpt_prise <<std::endl;

    if( liste_mangeable.empty()) {
      std::cout << "Liste vide  \n" << std::endl;
      if(cpt_prise == rafle_max ){
        std::cout << " Boucle cassée \n" <<std::endl;
        break;
      }
      else{
        std::cout << "\nVous pouvez prendre plus de pièce adverse que ça , regardez bien\n" << std::endl;
        cpt_prise = 0;
        x = x_initial;
        y = y_initial;
        bientot_mort.clear();
        this->setCoord(x_initial,y_initial);
        continue;
      }
    }
    else{
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
      nextPosition = this->nextMove( joueur_courant,joueur_adverse, taille,liste_mangeable.at(select).first, liste_mangeable.at(select).second);
      this->setCoord(  nextPosition.first, nextPosition.second);
      Piece* p = getPiece(joueur_adverse, liste_mangeable.at(select).first,  liste_mangeable.at(select).second);
      bientot_mort.push_back(p);
      cpt_prise++;
    }
  }
  for(int k = 0 ; k < bientot_mort.size() ; k++){
    bientot_mort.at(k)->setCoord(-1,-1);
  }
}


void Dame::jumpRafleBot(std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse, int taille,int x_initial, int y_initial , int rafle_max){

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
