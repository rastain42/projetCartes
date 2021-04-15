#include "carte.h"
#include <sstream>




string Carte::s_ordre[13]={"Deux","Trois","Quatre","Cinq","Six","Sept","Huit","Neuf","Dix","Valet","Dame","Roi","As"};
string Carte::s_couleur[4]={"Coeur","Pique","Carreau","Trefle"};

Carte::Carte(int ordre, int couleur):
    m_ordre(ordre), m_couleur(couleur)

{

}

string Carte::toString()
{
    stringstream buf;
    buf<<"voici la carte "<<s_ordre[m_ordre]<<" de " <<s_couleur[m_couleur]<<endl;
    return buf.str();
}

int Carte::getOrdre()
{
    return m_ordre;
}

void Cartes::ajouteDessous(Carte *c)
{
    m_tas.push_front(c);
    return;
}
