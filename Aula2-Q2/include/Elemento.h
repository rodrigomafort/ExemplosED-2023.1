#ifndef ELEMENTO_H
#define ELEMENTO_H

/*

A classe Elemento representa cada item que pode ser inserido nas listas.
Nesse exemplo, cada elemento possui apenas o atributo ID.
Caso seja necess�rio, � poss�vel criar outros atributos.

Vale observar tamb�m que o atributo ID foi tornado privado para impossibilitar a altera��o dessa informa��o.
Esse atributo se tornou "APENAS LEITURA".
Depois de instanciado, o atributo ID n�o pode ser alterado.

Nas pr�ximas aulas vamos avan�ar nos conceitos de encapsulamento, observando examente esse n�vel de controle.

Al�m disso, ao longo do curso vamos observar outras formas de implementar as listas sem a necessidade de uma classe para os itens.
(Interfaces e, em seguida, templates).

*/

class Elemento
{
    public:
        Elemento(int _ID); //Construtor requer o par�metro ID.
        //Como n�o existe o construtor em branco, todo elemento precisa ser constru�do j� com o seu ID.

        int ObterID() const; //M�todo que permite retornar o ID do objeto. Somente leitura.
        //o const na frente do m�todo indica que esse m�todo n�o altera nenhum atributo do objeto (n�o � permitido - resulta em erro de compila��o).

    protected:

    private:
        int ID; //Atributo ID � privado. Somente m�todos do pr�prio objeto podem visualizar/alterar essa informa��o
};

#endif // ELEMENTO_H
