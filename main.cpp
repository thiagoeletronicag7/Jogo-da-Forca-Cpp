#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

using namespace std;

bool venceu(char palavra_forca[], char tentativa_jogador[]);
bool perdeu(int vidas);

int main ()
{
    cout << "Este eh o Jogo da Forca Interativo" << endl;
    cout << "Para instrucoes de uso, leia o arquivo README.MD que se encontra na pasta do jogo!" << endl;

    //No futuro, encontrar uma forma de retirar as palavras desse arquivo e colocar em outro
    char palavra1[] = "paralelepipedo";
    char palavra2[] = "otorrinolaringologista";
    char palavra3[] = "pneumoultramicroscopicossilicovulcanoconiotico";
    char palavra4[] = "ampulheta";
    char palavra5[] = "jazz";

    cout << "Digite um unico numero entre 1 e 5:\n";//seletor da palavra do jogo
    int seletor = 0;
    while (seletor > 5 or seletor < 1)
    {
        cin >> seletor;
        if(seletor > 5 or seletor < 1) cout << "Valor invalido, digite um numero entre 1 e 5:\n";
    }

    char desafio[47]; //variável para armazenar a palavra do jogo

    switch (seletor) //passa a palavra escolhida para uma nova variável
    {
    case 1:
        memcpy(desafio, palavra1, sizeof(palavra1));
        break;
    case 2:
        memcpy(desafio, palavra2, sizeof(palavra2));
        break;
    case 3:
        memcpy(desafio, palavra3, sizeof(palavra3));
        break;
    case 4:
        memcpy(desafio, palavra4, sizeof(palavra4));
        break;
    case 5:
        memcpy(desafio, palavra5, sizeof(palavra5));
        break;
    }

    int tamanhoDaPalavra = strlen(desafio); //retorna o tamanho da palavra para a variável 
    cout << "Sua palavra tem " << tamanhoDaPalavra << " letras" << endl;

    for (int i = 0; i < tamanhoDaPalavra; i++) cout << "__|"; //Para mostrar para o usuário a quantidade de letras

    cout << endl;

    int vida = 5; //Quantidade de vidas do jogo
    char tentativa; //armazenará o valor digitado pelo usuário
    char saida[47]; //variável que será utilizada para printar a cada tentativa do usuário

    for (int i = 0; i < tamanhoDaPalavra; i++) //armazena um valor vazio a cada espaço do array
    {
        saida[i] = ' ';
    }
    
    int acerto = 0; //variável responsável em verificar se o usuário acertou alguma letra
    int comparaPalavras; //variável responsável em verificar se o usuário terminou a palavra
    
    while (vida)
    {
        cout << "Digite uma letra: \n";
        cin >> tentativa;
        tentativa = tolower(tentativa); //para evitar problemas do usuário informar uma letra maiúscula e o programa não reconhecer

        for(int i = 0; i <= tamanhoDaPalavra-1; ++i)
        {
            if (tentativa == desafio[i])
            {
                acerto = 1;
                saida[i] = tentativa;
            } else if(saida[i] == ' ')
            {
                saida[i] = '_';        
            }
            cout << saida[i] << "_|";         
        }

        cout << endl;
        if (acerto == 0) vida--; //se o usuário não acertou nenhuma, perde uma vida
        else acerto = 0; //se acertou alguma, reseta a variável de acerto e vai para próxima tentativa

        if(perdeu(vida)) //testa se o jogador perdeu o jogo e se errou alguma tentativa
        {
            cout << "GAME OVER!\nThiago Valentim - TunelessBat";
            system("pause");
            return 0;
        }

        if(venceu(desafio, saida)) return 0; //testa se o jogador venceu o jogo
        
    }

    cout << "GAME OVER!\nThiago Valentim - TunelessBat\n\n";
    system("pause");



    return 0;
}

//verifica se o jogador terminou a palavra
bool venceu(char palavra_forca[], char tentativa_jogador[])
{
    int comparaPalavras = strcmp(palavra_forca, tentativa_jogador);
    bool vitoria = false;
    if (comparaPalavras == 0)
        {
            cout << "\n\nParabens voce salvou uma vida!" << endl;
            cout << "Seu premio eh uma frase especial............." << endl;
            cout << "Vencer nao prova seus limites, tentar ate que a vitoria seja a unica opcao sim." << endl;
            cout << "Obrigado por jogar!!\nThiago Valentim - TunelessBat" << endl;
            system("pause");

            vitoria = true;
        }

        return vitoria;

}

bool perdeu(int vidas)
{
    bool derrota = false;
    switch (vidas) //para printar o boneco dos erros do jogo da forca
        {
        case 4:
            cout << "  ___   " << endl;
            cout << " (° °)" << endl;
            cout << "   |" << endl;
            break;
        case 3:
            cout << "  ___   " << endl;
            cout << " (° °)" << endl;
            cout << "   |" << endl;
            cout << "---" << endl;
            break;
        case 2:
            cout << "  ___   " << endl;
            cout << " (° °)" << endl;
            cout << "   |" << endl;
            cout << "-------" << endl;
            break;
        case 1:
            cout << "  ___   " << endl;
            cout << " (° °)" << endl;
            cout << "   |" << endl;
            cout << "-------" << endl;
            cout << "  /" << endl;
            cout << " /" << endl;
            break;
        case 0:
            cout << "  ___   " << endl;
            cout << " (° °)" << endl;
            cout << "   |" << endl;
            cout << "-------" << endl;
            cout << "  / \\" << endl;
            cout << " /   \\" << endl;
            derrota = true;
        default:
            break;
        }

    return derrota;
}