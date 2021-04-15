#ifndef CARTES_H
#define CARTES_H
#include "carte.h"
#include <list>
using namespace std;


class Cartes
{
private:
    list<Carte *> m_tas;
    list<Carte *> m_j1;
    list<Carte *> m_j2;

public:
    Cartes(int nb_tas=1);// par défaut un tas de 52 cartes
    Carte *enleve(); // enleve et retourne la carte du dessus(début de la liste)
    string toString();
    void supListe();
    int taille();
    void *ajoute(Carte c);
};

#endif // CARTES_H
