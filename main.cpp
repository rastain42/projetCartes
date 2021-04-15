#include <iostream>
#include "carte.h"
#include "cartes.h"
#include "parametres.h"


using namespace std;
#include "parametres.h"

void testAlea(){
    cout << "Test de nombres aléatoires:"<<endl;
    for(int i=0; i<200;i++)
    {
        cout<<Parametres::generateurAlea->get(Parametres::nbMax)<<"\t";
    }
    cout<<endl;
}



void testTas(){
    Cartes *sabot=new Cartes();
    cout<<sabot->toString()<<endl;
    // on enlève une carte
    Carte *c=sabot->enleve();
    cout<<"J'ai enlevé "<<c->toString()<<endl;
    cout<<sabot->toString()<<endl;
}
int main()
{
    testTas();
    return 0;
}
