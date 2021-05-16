#ifndef MOTEURBATAILLE_H
#define MOTEURBATAILLE_H
#import "cartes.h"
#include <list>
using namespace std;

class MoteurBataille
{
public:
    Cartes m_tasManche;
    Cartes m_tasj1;
    Cartes m_tasj2;
    MoteurBataille();
    virtual ~MoteurBataille();
    int joue1Manche();
    string mancheToString(int i);
    string egaliteToString();
    string victoireToString(string j);
};

#endif
