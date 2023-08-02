#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    setlocale(LC_ALL, "pt_BR.UTF-8"); //para aceitar acentos da língua portuguesa

    cout << "Este é o Jogo da Forca Interativo" << endl;
    cout << "Para instruções de uso, leia o arquivo README.MD que se encontra na pasta do jogo!" << endl;

    //No futuro, encontrar uma forma de retirar as palavras desse arquivo e colocar em outro
    char palavra1[] = "paralelepipedo";
    char palavra2[] = "otorrinolaringologista";
    char palavra3[] = "pneumoultramicroscopicossilicovulcanoconiótico";
    char palavra4[] = "ampulheta";
    char palavra5[] = "jazz";

    cout << "Digite um único número entre 1 e 5:\n";
    int seletor = 0;
    while (seletor > 5 or seletor < 1)
    {
        cin >> seletor;
        if(seletor > 5 or seletor < 1) cout << "Valor inválido, digite um número entre 1 e 5:\n";
    }

    char desafio[47];

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

    for (int i = 0; i < tamanhoDaPalavra; i++) cout << "__|";

    cout << endl;

    int vida = 5; //Quantidade de vidas do jogo
    char tentativa; //armazenará o valor digitado pelo usuário
    char saida[47];

    for (int i = 0; i < tamanhoDaPalavra; i++)
    {
        saida[i] = ' ';
    }
    
    int acerto = 0;
    int comparaPalavras;
    
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
        if (acerto == 0) vida--;
        else acerto = 0;

        switch (vida)
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
        default:
            break;
        }

        comparaPalavras = strcmp(desafio, saida);
        if (comparaPalavras == 0)
        {
            cout << "\n\nParabéns você salvou uma vida!" << endl;
            cout << "Seu prêmio é uma frase especial............." << endl;
            cout << "Vencer não prova seus limites, tentar até que a vitória seja a única opção sim." << endl;
            cout << "Obrigado por jogar!!\nThiago Valentim - TunelessBat" << endl;
            return 0;
        }
        
    }

    cout << "  ___   " << endl;
    cout << " (° °)" << endl;
    cout << "   |" << endl;
    cout << "-------" << endl;
    cout << "  / \\" << endl;
    cout << " /   \\" << endl;
    cout << "GAME OVER!\nThiago Valentim - TunelessBat";




    return 0;
}