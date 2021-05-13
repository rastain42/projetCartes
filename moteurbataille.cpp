#include "moteurbataille.h"
#include "parametres.h"
#include <sstream>
#include <list>
using namespace std;
MoteurBataille::MoteurBataille()
{
    Cartes *sabot = new Cartes(1);
    while (sabot->taille()>0) {
        m_tasj1.ajoute(sabot->enleveAlea());
        m_tasj2.ajoute(sabot->enleveAlea());
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
    if(m_tasj1.taille()==52 || m_tasj2.taille()==52){
        return 0;
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
        joue1Manche();
    }
}

void MoteurBataille::ajoutePile(Cartes j)
{
    j.ajouteTasDessous(m_tasManche);
}

string MoteurBataille::mancheToString(int i)
{
    Carte *cj1 = m_tasManche.enleve();
    Carte *cj2 = m_tasManche.enleve();
    stringstream buf;
    if(i==1){
        buf<<cj1->toString()<<" "<<cj2->toString()<<" j1 gagne la manche"<<endl;
        m_tasManche.ajoute(cj1);
        m_tasManche.ajoute(cj2);
        buf<<"il/elle remporte "<<m_tasManche.taille()/2<<" cartes"<<endl;
        m_tasj1.ajouteTasDessous(m_tasManche);
    } else {
        buf<<cj1->toString()<<" "<<cj2->toString()<<" j2 gagne la manche";
        m_tasManche.ajoute(cj1);
        m_tasManche.ajoute(cj2);
        buf<<"il/elle remporte "<<m_tasManche.taille()/2<<" cartes"<<endl;
        m_tasj2.ajouteTasDessous(m_tasManche);
    }
    return buf.str();
}

string MoteurBataille::egaliteToString()
{
    return "EGALITE";
}

string MoteurBataille::victoireToString(string j)
{
    return j + " a gagnÃ© !";
}
