#include "Dado.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Dado::Dado() //Dado padr�o de 6 faces
{
    faces = 6;
}

Dado::Dado(int _faces = 6) //Dados personalizados com qualquer n�mero de faces
{
    //ctor
    faces = _faces;
}

int Dado::Sortear()
{
    srand (time(NULL));
    faceSorteada = (rand() % faces) + 1;
    return faceSorteada;
}

Dado::~Dado()
{
    //dtor
}
