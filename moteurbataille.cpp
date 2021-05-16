#include "moteurbataille.h"
#include "parametres.h"
#include <sstream>
#include <list>
#include <iostream>

using namespace std;
MoteurBataille::MoteurBataille()
{
    Cartes *sabot = new Cartes(1);
    while (sabot->taille()>0) {
        m_tasj1.ajoute(sabot->enleveAlea(50));
        m_tasj2.ajoute(sabot->enleveAlea(50));
    }
    delete sabot;
}

MoteurBataille::~MoteurBataille()
{

}

int MoteurBataille::joue1Manche()
{
    Carte *c1 = m_tasj1.enleve();
    Carte *c2 = m_tasj2.enleve();
    if(m_tasj1.taille()==52){
        return 0;
    }else if( m_tasj2.taille()==52){
        return 4;
    }
    if(c1->getOrdre()>c2->getOrdre()) {
        m_tasManche.ajoute(c1);
        m_tasManche.ajoute(c2);
        return 1;
    } else if(c1->getOrdre()<c2->getOrdre()) {
        m_tasManche.ajoute(c1);
        m_tasManche.ajoute(c2);
        return 2;
    } else {
        m_tasManche.ajoute(c1);
        m_tasManche.ajoute(c2);
        cout<<"Egalite, la manche continue"<<endl;
        joue1Manche();
    }
}


string MoteurBataille::mancheToString(int i)
{
    Carte *cj1 = m_tasManche.enleve();
    Carte *cj2 = m_tasManche.enleve();
    stringstream buf;
    switch (i) {
        case 0:
            buf<<"le joueur 1 gagne la partie avec : "<<m_tasj1.toString()<<endl;
            m_tasManche.ajoute(cj1);
            m_tasManche.ajoute(cj2);
            buf<<"c'est la fin de la partie, veuillez relancer le programme"<<endl;
        break;
        case 1:
            buf<<cj1->toString()<<" et "<<cj2->toString()<<", le joueur 1 gagne la manche"<<endl;
            m_tasManche.ajoute(cj1);
            m_tasManche.ajoute(cj2);
            buf<<"il/elle remporte "<<m_tasManche.taille()/2<<" cartes"<<endl;
            m_tasj1.ajouteTasDessous(m_tasManche);
        break;
        case 2:
            buf<<cj1->toString()<<" et "<<cj2->toString()<<", le joueur 2 gagne la manche"<<endl;
            m_tasManche.ajoute(cj1);
            m_tasManche.ajoute(cj2);
            buf<<"il/elle remporte "<<m_tasManche.taille()/2<<" cartes"<<endl;
            m_tasj1.ajouteTasDessous(m_tasManche);
        break;
        case 4:
            buf<<"le joueur 1 gagne la partie avec : "<<m_tasj1.toString()<<endl;
            m_tasManche.ajoute(cj1);
            m_tasManche.ajoute(cj2);
            buf<<"c'est la fin de la partie, veuillez relancer le programme"<<endl;
        break;

    }
    return buf.str();
}
