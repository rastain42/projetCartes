#include "monalea.h"
#include<cstdlib>
#include<ctime>

MonAlea::MonAlea(int graine)
{
    if(graine==-1)
        srand((unsigned int)time(NULL));
    else
        srand((unsigned int)graine);
}

int MonAlea::get(int max)
{
    return rand()%max;
}
