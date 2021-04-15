#include "cartes.h"
#include <sstream>
#include <list>

Cartes::Cartes(int nb_tas)
{
    // pour tous les tas
    for(int t=0; t<nb_tas; t++) {
        //pour toutes les couleurs
        for(int c=0; c<4;c++) {
            //pour tous les ordres
            for(int o=0; o<13; o++) {
                m_tas.push_back(new Carte(o, c));
            }
        }
    }
}

Carte *Cartes::enleve()
{
    //instancier un itérateur de liste et l'initialiser à begin()
    auto it=m_tas.begin();
    // stocker le pointeur de la carte pointée
    Carte *c=*it;
    //enlever l'élément de la liste (remove)
    m_tas.remove(c);
    //retourner la carte
    return c;
}


string Cartes::toString()
{
    stringstream buf;
    for (auto it : m_tas) {
        buf<<it->toString()<<"\t";
    }
    return buf.str();
}

void Cartes::supListe()
{
    for(auto&& child : m_tas){
        delete child;
    }
}

int Cartes::taille()
{
    return m_tas.size();
}

void Cartes::ajoute(Carte *c)
{
    m_tas.push_back(c);
    return;
}

void Cartes::ajouteDessous(Carte *c)
{
    m_tas.push_front(c);
    return;
}

void Cartes::ajouteDessous(Cartes tas)
{
    for (auto it : tas.m_tas) {
        ajouteDessous(it);
    }

}



