#include "ListaSO.h"

#include <stdlib.h>
#include <iostream>
#include <exception>

ListaSO::ListaSO() //Construtor
{
    //ctor
    nElementos = 0; //Se a lista est� sendo constru�da agora, ela est� vazia: nElementos = 0

    //Como optei pela segunda forma de declarar a lista, estamos alocando a mem�ria para armazenar a lista
    //Observe que o sizeof retorna o tamanho necess�rio para armazenar um objeto da classe Elemento
    lista = (Elemento*) malloc (TAM_MAX * sizeof(Elemento));

    //Vale observar que na primeira op��o (como um vetor simnples), essa linha n�o seria necess�ria.
    //Pois ao declarar o vetor, j� estamos alocando a mem�ria.
}

ListaSO::~ListaSO()
{
    free(lista); //Ao destruir o objeto lista, libere a mem�ria alocada manualmente no construtor (malloc)
}

int ListaSO::Inserir(Elemento novo) //M�todo inserir
{
    if (ListaCheia() == 0) //Se a lista n�o est� cheia
    {
        if (ListaVazia() == 1) //Se a lista est� vazia
        {
            lista[0] = novo; //Inserir na primeira posi��o da lista
            nElementos++;
            return 1;
        }
        else
        {
            int pos = BuscaBinaria(novo.ObterID());
            if (pos < nElementos && lista[pos].ObterID() == novo.ObterID())
            {
                return 0; //N�o permitir inser��o de elementos duplicados

            }
            else
            {
                if (pos >= nElementos) //Se a busca retornou que o elemento deve entrar ap�s o �ltimo
                {
                    lista[nElementos] = novo; //Ocupar a �ltima posi��o da lista
                    nElementos++;
                    return 1;
                }
                else //Caso contr�rio
                {
                    AbrirEspaco(pos);
                    lista[pos] = novo; //Inserir o novo elemento na �ltima posi��o
                    nElementos++; //Incrementar o contador de elementos na lista
                    return 1; //Inser��o realizada com sucesso
                }
            }
        }
    }
    else
    {
        return 0; //Se a lista est� cheia, ent�o n�o � poss�vel inserir.
    }
}

int ListaSO::BuscaOrdenada(int ID) const//Busca ordendada
{
    int i = 0;
    while ( i < nElementos && lista[i].ObterID() <= ID) //Para pensar: qual � a diferen�a entre < e <= nesse caso? E se a lista aceitasse elementos com mesmo ID?
    {
        i++;
    }
    return i;
}

int ListaSO::BuscaBinaria(int ID) const
{
    return BuscaBinariaSeq(ID, 0, nElementos);
}

int ListaSO::BuscaBinaria(int ID, int ini, int fim) const
{
    if (ini >= fim) //Inicio e Fim se cruzaram (fim da busca)?
    {
        return ini; //Sim, retorne a posi��o onde isso ocorreu (ini)
    }
    else //N�o:
    {
        int meio = (fim + ini) / 2; //Identifique a posi��o central da lista iniciada em ini e terminada em fim (operadores inteiros -> divis�o inteira)
        if (lista[meio].ObterID() == ID) //O elemento buscado est� na posi��o meio da lista?
        {
            return meio; //Sim: retorne o �ndice meio (posi��o do elemento buscado)
        }
        else //N�o:
        {
            if (ID < lista[meio].ObterID()) //O elemento buscado � menor do que o elemento na posi��o meio?
            {
                return BuscaBinaria(ID, ini, meio); //Sim, logo o elemento est� ANTES da posi��o meio
            }
            else
            {
                return BuscaBinaria(ID, meio+1, fim); //N�o, logo o elemento est� DEPOIS da posi��o meio
            }
        }
    }
}

int ListaSO::BuscaBinariaSeq(int ID, int ini, int fim) const
{
    while (ini < fim)
    {
        int meio = (fim + ini) / 2; //Identifique a posi��o central da lista iniciada em ini e terminada em fim (operadores inteiros -> divis�o inteira)
        if (lista[meio].ObterID() == ID) //O elemento buscado est� na posi��o meio da lista?
        {
            return meio; //Sim: retorne o �ndice meio (posi��o do elemento buscado)
        }
        else //N�o:
        {
            if (ID < lista[meio].ObterID())
                fim = meio;
            else
                ini = meio + 1;
        }
    }
    return ini;
}


void ListaSO::AbrirEspaco(int pos)
{
    for (int i = nElementos; i > pos; i--)
    {
        lista[i] = lista[i-1];
    }
}

void ListaSO::FecharEspaco(int pos)
{
    for (int i = pos; i < nElementos - 1; i++)
    {
        lista[i] = lista[i+1];
    }
}

int ListaSO::Remover(int ID) //Remover o primeiro elemento que apresenta esse ID
{
    if (ListaVazia() == 0) //Se a lista n�o est� vazia
    {
        int pos = BuscaBinaria(ID); //Buscar
        if (pos >= nElementos || lista[pos].ObterID() != ID) //Se n�o foi localizado
        {
            return 0; //N�o � poss�vel remover
        }
        else
        {
            //Do contr�rio:
            FecharEspaco(pos);
            nElementos--; //Decrementar o n�mero de elementos da lista
            return 1; //Remo��o com sucesso
        }
    }
    else
    {
        return 0; //Se alista est� vazia, n�o � poss�vel remover
    }
}



int ListaSO::Alterar(int ID, Elemento elementoAtualizado)
{
    int pos = BuscaBinaria(ID); //Buscar pelo elemento
    if (pos >= nElementos || lista[pos].ObterID() != ID) //Se ele n�o foi encontrado
    {
        return 0; //Retornar 0 -> N�o foi poss�vel efetuar a altera��o
    }
    else
    {
        //Se o elemento foi localizado
        if (elementoAtualizado.ObterID() != ID)
        {
            Remover(ID);
            Inserir(elementoAtualizado);
        }
        else
        {
            lista[pos] = elementoAtualizado;
        }
        return 1; //Altera��o realizada com sucesso
    }
}

int ListaSO::ListaCheia() const
{
    if (nElementos >= TAM_MAX)
        return 1;
    else
        return 0;
}

int ListaSO::ListaVazia() const
{
    if (nElementos <= 0)
        return 1;
    else
        return 0;
}

int ListaSO::NumeroElementos() const
{
    return nElementos;
}

void ListaSO::Imprimir() const
{
    std::cout << "{ ";
    for (int i = 0; i < nElementos - 1; i++)
        std::cout << lista[i].ObterID() << ", ";
    if (nElementos > 0)
        std::cout << lista[nElementos - 1].ObterID();
    std::cout << " } " << std::endl;
}

Elemento& ListaSO::operator[](int pos)
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
