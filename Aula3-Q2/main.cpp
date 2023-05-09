#include <iostream>
#include <locale>

#include "Jogo.h"
#include "Jogador.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Portuguese"); //Permitir impress�o de texto com acentua��o sem erros

    int njogadores, ndados, fdados;

    cout << "Digite o n�mero de dados: " << endl;
    cin >> ndados;

    cout << "Digite o n�mero de faces dos dados: " << endl;
    cin >> fdados;

    cout << "Digite o n�mero de jogadores: " << endl;
    cin >> njogadores;

    Jogo jogo(ndados,fdados);

    for (int ctJ = 1; ctJ <= njogadores; ctJ++)
    {
        string nome;
        cout << "Digite o nome do Jogador " << ctJ << endl;
        cin >> nome;

        Jogador j(nome);

        float vaposta;
        cout << "Digite o valor da aposta do Jogador " << nome << endl;
        cin >> vaposta;

        do
        {
            int naposta;
            cout << "Digite o n�mero apostado pelo Jogador " << nome << endl;
            cin >> naposta;

            try
            {
                j.FazerAposta(naposta,vaposta);
                jogo.AdicionarJogador(j);
                break; //Se n�o houver uma exce��o, vamos interromper a repeti��o do/while.
            }
            catch (...)
            {
                cout << "Essa aposta j� existe. Tente novamente." << endl;
            }
        }
        while (true);
    }

    jogo.Jogar();

    return 0;
}
