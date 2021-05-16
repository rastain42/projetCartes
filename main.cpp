#include <iostream>
#include "carte.h"
#include "cartes.h"
#include "parametres.h"
#include "moteurbataille.h"

using namespace std;
#include "parametres.h"


int main(){

 MoteurBataille *jeu = new MoteurBataille();
 cout<<"Bienvenue dans ce jeu de bataille"<<endl;
 cout<<"52 cartes ont étées distribuées entre les deux joueurs"<<endl;
 jeu->mancheToString(jeu->joue1Manche());

 delete jeu;
 return 0;
}
