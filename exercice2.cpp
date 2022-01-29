/*
  Exercice 2 - Morpion

  Nous allons écrire un jeu simpliste de morpion. Le morpion est un jeu à deux
  joueurs qui consiste, à tour de rôle, de poser une croix (X) ou un rond (O)
  dans une grille 3x3. Un joueur gagne s'il aligne 3 symboles identiques en
  ligne, colonne ou diagonale.

  Q1 - Définissez un type 'grille' à base de std::array pour représenter la
  grille de jeu

  Q2 - Créez une valeur booléenne 'fin' valant false. Utilisez-la dans une
  boucle while dont la condition d'arrêt est le fait que cette variable vaille
  true. Vérifiez que le programme ne s'arrête pas.

  Q3 - Créez à l'endroit adéquat une variable 'symbole' de type char. Cette
  variable vaut 'X' au démarrage. Faites en sorte que, à chaque tour de boucle
  while, sa valeur alterne entre 'X' et 'O'.

  Q4 - Modifiez la boucle afin d'afficher un texte invitant le symbole courant à
  entrer sa position de jeu. Lisez ensuite une paire d'entiers entre 0 et 2.
  Cette paire d'entiers représente la coordonnée (x,y) dans la grille où le
  symbole courant doit être placé.

  Q5 - Construisez à l'endroit adéquat une variable de type 'grille' et mettez à
  jour sa valeur et affichez la à chaque itération.

  Q6 - Implémentez une série de tests qui vérifie après chaque coup si le joueur
  courant a gagné. Si c'est le cas, annoncez sa victoire et mettez la variable
  fin à true pour arrêter le jeu.

  QBONUS - Ajoutez tous les tests nécessaires à la capture des erreurs dues à
  l'entrée des positions des joueurs : case hors grille, case déjà utilisée, etc
  ...
*/

#include <array>
#include <iostream>


bool test_win(std::array<std::array<char, 3>, 3> t, char symb){
    if((t[0][0] == t[0][1] && t[0][2] == t[0][1] && t[0][0] == symb) || (t[1][0] == t[1][1] && t[1][2] == t[1][1]&& t[1][1] == symb) || 
    (t[2][0] == t[2][1] && t[2][2] == t[2][1] && t[2][0] == symb) || (t[2][0] == t[0][0] && t[1][0] == t[0][0] && t[2][0] == symb) || 
    (t[2][1] == t[0][1] && t[1][1] == t[0][1] && t[0][1] == symb) || (t[2][2] == t[0][2] && t[1][2] == t[0][2] && t[0][2] == symb) ||
    (t[0][0] == t[1][1] && t[0][0] == t[2][2] && t[0][0] == symb) || (t[0][2] == t[1][1] && t[2][0] == t[1][1] && t[0][2] == symb)){
        return true;
    }
    return false;
}

bool test_fin(std::array<std::array<char, 3>, 3> t){
  for(size_t i=0;i<t.size();i++){
    for(int j=0;j<t[0].size();j++){
      if(t[i][j] == ' '){
        return false;
      }
    }
  }
  return true;
}


int main(int, char **) {
  char choix;

  do{
    //Q1
    std::array<std::array<char, 3>, 3> grille;
    //Q2
    bool fin = false;
    bool pos_ok;
    char symbole = 'X';
    int x, y;
    grille= {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}};
    std::cout << "Bienvenue au jeu du morpion : \n \n";
    while(fin == false){
      //Q4
      //Q5
      pos_ok = false;
      std::cout << "Voici la table de jeu : \n";
      std::cout << grille[0][0] << "|" << grille[0][1] << "|" << grille[0][2] << "\n";
      std::cout << "-" << "-" << "-" << "-" << "-" << "\n";
      std::cout << grille[1][0] << "|" << grille[1][1] << "|" << grille[1][2] << "\n";
      std::cout << "-" << "-" << "-" << "-" << "-" << "\n";
      std::cout << grille[2][0] << "|" << grille[2][1] << "|" << grille[2][2] << "\n";

      std::cout << symbole << " : c'est à ton tour de jouer. Donne deux enters entre 1 et 3 : \n";
      std::cout << "Numéro de ligne  : ";
      std::cin >> x;
      std::cout << "Numéro de colonne : ";
      std::cin >> y;
      std::cout << "\n";
      while(pos_ok == false){
        if(x > 3 || x < 1){
          std::cout << "Erreur : Numéro de ligne incorrect (entre 1 et 3). \n";
        }
        else if(y > 3 || y < 1){
          std::cout << "Erreur : Numéro de colonne incorrect (entre 1 et 3). \n";
        }
        else if(grille[x-1][y-1] != ' '){
          std::cout << "Erreur : Case déjà prise. \n";
        }
        else{
          pos_ok = true;
          break;
        }
        std::cout << symbole << " : c'est à ton tour de jouer. Donne deux enters entre 1 et 3 : \n";
        std::cout << "Numéro de ligne : ";
        std::cin >> x;
        std::cout << "Numéro de colonne : ";
        std::cin >> y;
        std::cout << "\n";
      }
      grille[x-1][y-1] = symbole;

      if(test_win(grille, symbole) == true){
        std::cout << grille[0][0] << "|" << grille[0][1] << "|" << grille[0][2] << "\n";
        std::cout << "-" << "-" << "-" << "-" << "-" << "\n";
        std::cout << grille[1][0] << "|" << grille[1][1] << "|" << grille[1][2] << "\n";
        std::cout << "-" << "-" << "-" << "-" << "-" << "\n";
        std::cout << grille[2][0] << "|" << grille[2][1] << "|" << grille[2][2] << "\n";
        std::cout << "Le joueur " << symbole << " a gagné. \n";
        fin = true;
        break;
      }

      if(test_fin(grille) == true){
        std::cout << "Egalite entre le joueur X et 0. \n";
        fin = true;
      }
      //Q3
      if(symbole == 'X'){
        symbole = 'O';
      }
      else{
        symbole = 'X';
      }
    }
    std::cout << "Nouvelle partie ? O ou N :";
    std::cin >> choix;
  }while(choix == 'O');

  std::cout << "Merci d'avoir jouer au jeu du morpion. A bientot ! \n";
  return 0;
}