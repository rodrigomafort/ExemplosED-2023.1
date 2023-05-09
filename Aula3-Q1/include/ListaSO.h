#ifndef LISTASNO_H
#define LISTASNO_H

#include "Elemento.h"

#define TAM_MAX 100

/*

Classe que implementa Lista Sequencial Ordenada.
Assim como nas listas n�o ordenadas, cada item dessa lista � um objeto da classe Elemento.

Essa classe implementa todos os m�todos necess�rios para lidar com listas de aloca��o sequencial - n�o ordenadas.
M�todos inserir, remover, buscar e alterar.

Em adi��o a esses, outros m�todos foram implementados para facilitar a leitura (listaCheia, listaVazia, etc.. ).

O m�todo operator[] foi adicionado para demonstrar a possibilidade da linguagem de acessar posi��es da lista como um vetor.
*/

class ListaSO
{
    public:
        ListaSO(); //Construtor - Cria uma lista em branco
        ~ListaSO(); //Destrutor - libera a mem�ria utilizada na lista

        int Inserir(Elemento novo); //Inserir um novo elemento
        int Remover(int ID); //Remover o primeiro elemento que apresenta esse ID
        int Alterar(int ID, Elemento elementoAtualizado); //M�todo para alterar um elemento. Localiza o ID e altera o elemento (atribuindo o novo na posi��o do antigo).

        int BuscaOrdenada(int ID) const; //Busca ordenada pelo primeiro elemento que apresenta esse ID. Se n�o for localizado, retorna a posi��o onde o elemento deve ser inserido.
        int BuscaBinaria(int ID) const; //Busca bin�ria pelo primeiro elemento que apresenta esse ID. Se n�o for localizado, retorna a posi��o onde o elemento deve ser inserido

        int ListaCheia() const; //M�todo que indica se a lista est� cheia ou n�o (nElementos >= TAM_MAX)
        int ListaVazia() const; //M�todo que indica se a lista est� vazia ou n�o (nElementos <= 0)
        int NumeroElementos() const; //Retorna o n�mero de elementos na lista

        void Imprimir() const; //M�todo auxiliar - apenas para visualiza��o - imprime toda a lista

        Elemento& operator[](int pos); //Permite implementar o operador [] (usado em vetores e matrizes).
        //Dada a posi��o, retorna um ponteiro para o elemento na posi��o pos da lista.
        //Como ele retorna um ponteiro, as informa��es do elemento podem ser alteradas (com exce��o do ID - que � privado).

    protected:
        void AbrirEspaco(int pos); //Classes que herdam de ListaSO podem acessar AbrirEspaco
        void FecharEspaco(int pos); //Classes que herdam de ListaSO podem acessar FecharEspaco

        int BuscaBinaria(int ID, int ini, int fim) const;
        int BuscaBinariaSeq(int ID, int ini, int fim) const;

    private:
        int nElementos; //N�mero de elementos na lista -- Como � privado, s� pode ser modificado pelos m�todos Inserir e Remover.

        //Duas op��es: Declarar a lista como um vetor comum
        //Elemento lista[TAM_MAX]; // -- como um vetor de Elemento

        //Ou usar o comando malloc - nesse caso a lista � representada por um ponteiro.
        Elemento* lista; //Vou optar pela segunda forma para exemplificar o construtor e o destrutor da classe

};

#endif // LISTASNO_H
