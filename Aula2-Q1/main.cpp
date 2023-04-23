#include <iostream> //Biblioteca com os comandos de entrada e sa�da
#include <locale> //Biblioteca com fun��es para localiza��o (formato de n�meros, acentos, etc...)
#include "Coordenada.h" //importar o arquivo com a classe Coordenada

using namespace std; //Todas as fun��es nativas est�o no "universo" std.
//Ao declarar que usamos esse universo, o programa consegue visualizar essas fun��es.
//Sem esse comando, todos os comandos nativos (entrada, sa�da, etc.. ) devem vir precedidos por std::
//std::cout -> chamada a fun��o cout, definida no namespace std.

int main()
{
    setlocale(LC_CTYPE, "Portuguese"); //Permitir impress�o de texto com acentua��o sem erros

    Coordenada p1; //Chamada ao construtor sem par�metros
    p1.X = 0;
    p1.Y = -3.0;

    Coordenada p2(3.0, 4.0); //Chamada ao segundo construtor - recebe dois n�meros reais (double)

    cout << "Dist�ncia: " << p1.CalcularDistancia(p2) << endl; //endl -> atalho para \n
    cout << "Dist�ncia: " << p2.CalcularDistancia(p1) << endl; //Tem que retornar o mesmo valor

    return 0;
}
