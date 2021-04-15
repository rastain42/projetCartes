#ifndef CARTE_H
#define CARTE_H
#include <string>
using namespace std;


class Carte
{
private:
    int m_ordre;
    int m_couleur;
public:
    Carte(int ordre, int couleur);
     static string s_ordre[13];
     static string s_couleur[4];
     string toString();
     int getOrdre();
};

#endif // CARTE_H
