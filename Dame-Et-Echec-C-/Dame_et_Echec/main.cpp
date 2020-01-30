#include<iostream>
#include<string>
#include <climits>
#include <fstream>

#include "JeuDame.hpp"
#include "JeuEchec.hpp"
#include "JeuDameAnglaise.hpp"



void afficher_couple(std::vector< std::pair<Piece*,int> > liste){
  for(int i = 0; i < liste.size() ; i++){
    std::cout << "choix "<< i << " coordonnees X: " << liste.at(i).first->getX()<< " Coordonnee Y: " << liste.at(i).first->getY() <<
    " Peut prendre "<< liste.at(i).second  << " piece(s)\n" << std::endl;
  }
}

void afficher_couple(std::vector< std::pair<int,int> > liste){
  for(int i = 0; i < liste.size() ; i++){
    std::cout << "choix "<< i << " coordonnees X: " << liste.at(i).first<< " Coordonnee Y: " << liste.at(i).second << std::endl;
  }
}


void sauvegarde(std::string jeu, int tour, std::vector<Piece*> & joueur_courant, std::vector<Piece*> & joueur_adverse){
  std::ofstream fichier;
  fichier.open(jeu + std::to_string(tour));
  if(!fichier){
    std::cout<<"Erreur d'ouverture de fichier..."<<std::endl;
  }
  else{
    fichier << jeu <<std::endl;
    for(int i = 0; i < joueur_courant.size(); i++){
      fichier << joueur_courant.at(i)->getX()<< " "<<joueur_courant.at(i)->getY()<<" "<<joueur_courant.at(i)->getCouleur()<<std::endl;
    }
    for(int j = 0; j < joueur_adverse.size(); j++){
      fichier << joueur_adverse.at(j)->getX()<< " "<<joueur_adverse.at(j)->getY()<<" "<<joueur_adverse.at(j)->getCouleur()<<std::endl;
    }
  }
  fichier.close();
}


void chargement( Jeu*  a , JeuDame & d,JeuDameAnglaise & da, JeuEchec & e,int tour, std::string nomf){
  std::ifstream fichier;
  std::string nom_fic = nomf ; // std::to_string(tour);
  std::cout<<"nom de fichier au chargement : "<<nom_fic<<std::endl;
  fichier.open(nom_fic);
  std::cout<<"ouverture fichier"<<std::endl;
  std::string ligne;
  std::string jeu;



  int numLigne=0;
  int i=0;
  int j=0;

  if(fichier.is_open()){
    std::cout<<"bonne ouverture fichier"<<std::endl;
    while(getline(fichier, ligne)){
      if(numLigne == 0){
        jeu = ligne;
        if(jeu == "dame"){
          a = &d;
          std::cout<<"Jeu crée"<<std::endl;
        }
        else{
          if(jeu == "dame_anglaise"){
            a = &da;
          }
          else{
            if(jeu == "echec"){
              a = &e;
            }
          }
        }
      }
      else{
        //modification jeu de dames
        if(jeu == "dame"){
          if(ligne[4] == 'b' ||ligne[6] == 'b'){
            std::cout<<"modifications coord j1 : "<<i<<std::endl;
            //modification coordonnes j1
            //set coord x et y, ASCII 48 ="0" permet de trouver l'entier correspondant aux coordonnees
            if(ligne[0] == '-'){
              a->getPJ1().at(i)->setCoord(-1,-1);
            }
            else{
              int x = ligne[0] -48;
              int y = ligne[2] -48;
              a->getPJ1().at(i)->setCoord(x,y);
              std::cout << "x : "<<a->getPJ1().at(i)->getX()<<" y : "<<a->getPJ1().at(i)->getY()<<std::endl;
            }
            i = i+1;
          }
          if(ligne[4] == 'n' ||ligne[6] == 'n'){
            std::cout<<"modifications coord j2 : "<<j<<std::endl;
            //set coord x et y
            if(ligne[0] == '-'){
              a->getPJ2().at(j)->setCoord(-1,-1);
            }
            else{
              int x = ligne[0] -48;
              int y = ligne[2] -48;
              a->getPJ2().at(j)->setCoord(x,y);
              std::cout << "x : "<<a->getPJ2().at(j)->getX()<<" y : "<<a->getPJ2().at(j)->getY()<<std::endl;
            }
            j = j+1;
          }
        }
      }
      numLigne = numLigne+1;
    }
    fichier.close();
    if(tour % 2 == 0){
      a->affiche(a->getPJ1(),a->getPJ2(),a->getSize());
    }
    else{
      a->affiche(a->getPJ2(),a->getPJ1(),a->getSize());
    }
  }
  else{
    std::cout<<"Impossible d'ouvrir le fichier"<<std::endl;
  }
  // sauvegarde(jeu, tour, a->getPJ1(), a->getPJ2());
}


void inputHelp( Jeu* a , JeuDame & d, JeuDameAnglaise & da, JeuEchec & e,std::string nomJeu){
  std::string inputUser;
  std::string tmp;
  std::cout << "\nRejouer la partie: nomDeJeu+0"<<"\nRevenir au n-ieme tour: nomDeJeu+numTour"<<std::endl;
  std::cin >> inputUser;
  tmp = inputUser;
  int tour;
  if(inputUser.compare(0,nomJeu.size(),nomJeu)==0){
    if(nomJeu == "dame"){
      tmp = tmp.erase(0,4);
      tour = std::stoi(tmp);
      chargement( a , d, da, e,tour, nomJeu.append(tmp));
    }
    if(nomJeu == "echec"){
      tmp = tmp.erase(0,5);
      tour = std::stoi(tmp);
      chargement( a , d, da, e, tour, nomJeu.append(tmp));
    }
    if(nomJeu == "dame_anglaise"){
      tmp = tmp.erase(0,13);
      tour = std::stoi(tmp);
      chargement( a , d, da, e, tour, nomJeu.append(tmp));
    }
  }
}


void botJoueur(Jeu* a, std::string nomJeu, int taille, std::vector<Piece*> joueur_courant, std::vector<Piece*> joueur_adverse){

  int select;
  int selectChoix;
  Piece* choix;
  int x_choisi;
  int y_choisi;
  std::pair<int,int> coordXY;
  std::vector<std::pair<Piece*,int>> peut_manger;
  std::vector<std::pair<int,int>> peut_se_deplacer;

  std::cout << "choix setcoord"<<std::endl;
  peut_manger = Piece::prisePossible(joueur_courant,joueur_adverse,taille);
  std::cout << "peut manger"<<std::endl;
  if( (nomJeu == "dame" || nomJeu == "dame anglaise") && peut_manger.size() > 0 ){
    //std::cout << "peut_manger > 0"<<std::endl;
    if(peut_manger.size() == 1){
      //std::cout << "peut_manger == 1"<<std::endl;
      selectChoix = 0;
    }
    if(peut_manger.size()>1){
      std::cout << "peut_manger > 1"<<std::endl;
      selectChoix = rand() % peut_manger.size();
    }
    //std::cout << "choix = peut_manger.at"<<std::endl;
    choix = peut_manger.at(selectChoix).first;
    //std::cout << "appel jumpRafleBot"<<std::endl;
    choix->jumpRafleBot(joueur_courant,joueur_adverse,taille,choix->getX(),choix->getY(),peut_manger.at(selectChoix).second);
  }
  else{

    do{
      x_choisi = rand() % taille;
      y_choisi = rand() % taille;
      std::cout << "x = "<<x_choisi<< " y = "<<y_choisi<<std::endl;
      if(a->coordonneeValide(joueur_courant,joueur_adverse,x_choisi,y_choisi)){
        std::cout << "coordonneeValide"<<std::endl;
        choix = Piece::getPiece(joueur_courant,x_choisi,y_choisi);
        std::cout << "choix"<<std::endl;
        peut_se_deplacer = choix->mouvementsPossible(taille,joueur_courant,joueur_adverse);
        std::cout << "peut_se_deplacer"<<std::endl;
        if(peut_se_deplacer.size() == 1){
          std::cout << "peut_se_deplacer == 1"<<std::endl;
          select = 0;
        }
        if(peut_se_deplacer.size()>1){
          std::cout << "else peut_se_deplacer"<<std::endl;
          select = rand() % peut_se_deplacer.size();
        }
        std::cout << "select random"<<std::endl;
      }
    }while(peut_se_deplacer.size() == 0);
    std::cout << "fin while"<<std::endl;
    choix->setCoord(peut_se_deplacer.at(select).first,peut_se_deplacer.at(select).second);
    choix->promotion(joueur_courant,taille);
    if(nomJeu == "echec"){
      choix->setADejaBouge(true);
      Piece* a_manger = Piece::getPiece(joueur_adverse,choix->getX(),choix->getY());
      if(a_manger != NULL ){
        a_manger->setCoord(-1,-1);
      }
    }
  }
}


int main(){

  std::cout << "Choisissez votre jeu parmi ceux qui été implémenté ; dame , echec ou dame anglaise" << '\n';

  Jeu* a;
  JeuDame d;
  JeuEchec e;
  JeuDameAnglaise da;

  std::vector<Piece*> tmp_piece;
  std::pair<int,int> coordXY;
  std::string choixHelp;

  std::string jeu;
  do{
    std::cin >> jeu;
  }while(jeu != "dame" && jeu != "dame_anglaise" && jeu != "echec");

  if(jeu == "dame" ){
    a =  &d;
  }
  else{
    if(jeu == "dame_anglaise"){
      a =  &da;
    }
    else{
      a =  &e;
    }
  }

  int taille = a->getSize();
  std::vector<Piece*>  joueur_courant(a->getPJ1());
  std::vector<Piece*>  joueur_adverse(a->getPJ2());
  std::vector<Piece*> tmp;

  int x_choisi;
  int y_choisi;
  int select;
  Piece* choix;
  std::vector<std::pair<Piece*,int>> peut_manger;
  std::vector<std::pair<int,int>> peut_se_deplacer;

  int tour = 0;

  bool a_rejoue;

  while(!a->victoire(joueur_courant, joueur_adverse)){     //Tant que aucun joueur n'a gagne ==> Winning Condition plus tard

  if(joueur_courant.at(0)->getCouleur() == "blanc"){ //////////////////////

    a_rejoue = false;

    if(tour % 2 == 0){
      a->affiche(joueur_courant,joueur_adverse,taille);
      sauvegarde(jeu ,tour,joueur_courant,joueur_adverse);
    }
    else{
      a->affiche(joueur_adverse,joueur_courant,taille);
    }

    std::cout << "\n\nJoueur "+joueur_courant.at(0)->getCouleur() +"\n" << std::endl;
    peut_manger = Piece::prisePossible(joueur_courant,joueur_adverse,taille);

    if( (jeu == "dame" || jeu == "dame_anglaise") && peut_manger.size() > 0 ){

      std::cout << "\n\nVous pouvez manger des Pieces adverses\n" << std::endl;
      std::cout << "Liste des Pieces offrant les meilleures rafles\n" << std::endl;
      afficher_couple(peut_manger);
      std::cout << "\nSelectionnez un des choix disponibles en inscrivant la valeur qui leur est associée\n" << std::endl;

      std::cin >> select;
      while (std::cin.fail() || select < 0 || select >= peut_manger.size() ){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
        std::cin >> select;
      }

      choix = peut_manger.at(select).first;
      choix->jumpRafle(joueur_courant,joueur_adverse,taille,choix->getX(),choix->getY(),peut_manger.at(select).second);
    }

    else{

      std::cout << "\n\nVoulez vous  rejouer un coup ou recommencer la partie ; OUI ou NON\n" << std::endl;
      std::cin>> choixHelp;
      while(std::cin.fail()){
        if(choixHelp.compare("oui")==0 || choixHelp.compare("non")==0){
          std::cout <<"Veuillez repondre par oui ou non, merci....." << std::endl;
          std::cin >> choixHelp;
        }
        else{
          break;
        }
      }
      if(choixHelp == "oui"){
        inputHelp( a , d, da, e, jeu);
        a_rejoue = true;
      }

      else{
        do{
          do{
            std::cout << "\nInserez les coordonnes de la piece que vous souhaitez deplacer" << std::endl;
            std::cin >> x_choisi;
            std::cin >> y_choisi;
            while (std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(INT_MAX, '\n');
              std::cout << "Vous devez entrer des chiffres. Recommencez" << std::endl;              //TRANSFORMER EN METHODE
              std::cin >> x_choisi;
              std::cin >> y_choisi;
            }
          }while(!a->coordonneeValide(joueur_courant,joueur_adverse,x_choisi,y_choisi));
          choix = Piece::getPiece(joueur_courant,x_choisi,y_choisi);
          peut_se_deplacer = choix->mouvementsPossible(taille,joueur_courant,joueur_adverse);
          if(peut_se_deplacer.size() == 0){
            std::cout<< "Ce Piece n'a aucun deplacement possible\n"<<std::endl;
          }
        }while(peut_se_deplacer.size() == 0);


        afficher_couple(peut_se_deplacer);
        std::cout << "Selectionnez un des choix disponibles en inscrivant la valeur qui leur est associée\n" << std::endl;
        std::cin >> select;
        while (std::cin.fail() || select <0 || select>=peut_se_deplacer.size()  ){
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cout << "Vous devez une valeur qui figure parmis les choix possibles. Recommencez" << std::endl;
          std::cin >> select;
        }
        choix->setCoord(peut_se_deplacer.at(select).first,peut_se_deplacer.at(select).second);
        choix->promotion(joueur_courant,taille);
        if(jeu == "echec"){
          choix->setADejaBouge(true);
          Piece* a_manger = Piece::getPiece(joueur_adverse,choix->getX(),choix->getY());
          if(a_manger != NULL ){
            a_manger->setCoord(-1,-1);
          }
        }
      }
    }
  }
  else{
    botJoueur(a, jeu, taille, joueur_courant,joueur_adverse);
  }

  //Changement de liste du joueur courant avant une nouvelle boucle
  if(!a_rejoue){
    tour++;
    tmp = joueur_courant;
    joueur_courant= joueur_adverse;
    joueur_adverse = tmp;
  }
}

//Les deletes

for(int clear = 0 ; clear < a->getPJ2().size() ; clear ++){
  delete a->getPJ2().at(clear);
}

for(int clear2 = 0 ; clear2 < a->getPJ1().size() ; clear2 ++){
  delete a->getPJ1().at(clear2);
}
delete a;

}
