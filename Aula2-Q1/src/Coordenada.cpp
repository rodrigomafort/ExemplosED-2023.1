#include "Coordenada.h"
#include <math.h>

Coordenada::Coordenada() //Construtor sem par�metros da classe Coordenada
{
    //ctor
}

Coordenada::Coordenada(double _X, double _Y)
{
    X = _X;
    Y = _Y;
}

double Coordenada::CalcularDistancia(Coordenada outra) //Observe o Coordenada:: -> indica que estamos implementando a fun��o CalcularDistancia da classe Coordenada
{
    double dif_x = abs(X - outra.X); //dist�ncia absoluta entre as coordenadas X (abs -> n�mero sem sinal)
    double dif_y = abs(Y - outra.Y); //dist�ncia absoluta entre as coordenadas Y

    double dist = sqrt(pow(dif_x,2) + pow(dif_y,2));
    return dist;
}

