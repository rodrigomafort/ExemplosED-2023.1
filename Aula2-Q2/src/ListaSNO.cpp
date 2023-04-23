#include "ListaSNO.h"

#include <stdlib.h>
#include <iostream>
#include <exception>

ListaSNO::ListaSNO() //Construtor
{
    //ctor
    nElementos = 0; //Se a lista est� sendo constru�da agora, ela est� vazia: nElementos = 0

    //Como optei pela segunda forma de declarar a lista, estamos alocando a mem�ria para armazenar a lista
    //Observe que o sizeof retorna o tamanho necess�rio para armazenar um objeto da classe Elemento
    lista = (Elemento*) malloc (TAM_MAX * sizeof(Elemento));

    //Vale observar que na primeira op��o (como um vetor simnples), essa linha n�o seria necess�ria.
    //Pois ao declarar o vetor, j� estamos alocando a mem�ria.
}

ListaSNO::~ListaSNO()
{
    free(lista); //Ao destruir o objeto lista, libere a mem�ria alocada manualmente no construtor (malloc)
}

int ListaSNO::Inserir(Elemento novo) //M�todo inserir
{
    if (ListaCheia() == 0) //Se a lista n�o est� cheia
    {
        lista[nElementos] = novo; //Inserir o novo elemento na �ltima posi��o
        nElementos++; //Incrementar o contador de elementos na lista
        return 1; //Inser��o realizada com sucesso
    }
    else
    {
        return 0; //Se a lista est� cheia, ent�o n�o � poss�vel inserir.
    }
}

int ListaSNO::Buscar(int ID) const//Busca exaustiva
{
    for (int i = 0; i < nElementos; i++) //Para cada posi��o da lista
    {
        if (lista[i].ObterID() == ID) //Se o ID � igual ao procurado
            return i; //Retorne a posi��o
    }
    return -1; //Se nenhum return foi executado at� agora, o elemento n�o est� na lista.
}

int ListaSNO::Remover(int ID) //Remover o primeiro elemento que apresenta esse ID
{
    if (ListaVazia() == 0) //Se a lista n�o est� vazia
    {
        int pos = Buscar(ID); //Buscar
        if (pos < 0) //Se n�o foi localizado
        {
            return 0; //N�o � poss�vel remover
        }
        else
        {
            //Do contr�rio:
            lista[pos] = lista[nElementos-1]; //Mover o �ltimo elemento para essa posi��o (fechar o buraco)
            nElementos--; //Decrementar o n�mero de elementos da lista
            return 1; //Remo��o com sucesso
        }
    }
    else
    {
        return 0; //Se alista est� vazia, n�o � poss�vel remover
    }
}



int ListaSNO::Alterar(int ID, Elemento elementoAtualizado)
{
    int pos = Buscar(ID); //Buscar pelo elemento
    if (pos < 0) //Se ele n�o foi encontrado
    {
        return 0; //Retornar 0 -> N�o foi poss�vel efetuar a altera��o
    }
    else
    {
        //Se o elemento foi localizado
        lista[pos] = elementoAtualizado; //Vamos substituir esse elemento pelo elementoAtualizado
        return 1; //Altera��o realizada com sucesso
    }
}

int ListaSNO::ListaCheia() const
{
    if (nElementos >= TAM_MAX)
        return 1;
    else
        return 0;
}

int ListaSNO::ListaVazia() const
{
    if (nElementos <= 0)
        return 1;
    else
        return 0;
}

int ListaSNO::NumeroElementos() const
{
    return nElementos;
}

void ListaSNO::Imprimir() const
{
    std::cout << "{ ";
    for (int i = 0; i < nElementos - 1; i++)
        std::cout << lista[i].ObterID() << ", ";
    if (nElementos > 0)
        std::cout << lista[nElementos - 1].ObterID();
    std::cout << " } " << std::endl;
}

Elemento& ListaSNO::operator[](int pos)
{
    //Se pos � uma posi��o v�lida e ocupada na lista:
    if (pos >= 0 && pos < nElementos)
    {
        return lista[pos];  //Retorne o elemento que est� nessa posi��o.
        //Importante: esse return retorna um ponteiro (impl�cito) para a posi��o pos da lista
        //Esse ponteiro permite alterar diretamente essa posi��o da lista.
    }
    else
    {
        //caso contr�rio: dispare uma exce��o (tal como um erro).
        throw std::invalid_argument("Posi��o Inv�lida.");
        //Se n�o tratarmos as exce��es, o programa � interrompido.
        //Vamos abordar esse assunto no curso de POO
    }
}
