#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
    public:
        Coordenada(); //Construtor sem par�metros
        Coordenada(double _X, double _Y); //Segundo construtor - Recebe par�metros X e Y

        double X; //Atributo p�blico X
        double Y; //Atributo p�blico Y
        //Para pensar: faz sentido proteger essa informa��o?


        double CalcularDistancia(Coordenada outra); //Prot�tipo do m�todo CalcularDist�ncia

    protected:

    private:
};

#endif // COORDENADA_H
