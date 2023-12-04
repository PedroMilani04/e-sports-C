#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "jogadores.h"

#define MAX_PLAYERS 50
#define MAX_NAME_LENGTH 50

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opcao, valorPontuacao;
    char nomeJogador[MAX_NAME_LENGTH];

    JOGADOR jogadores[MAX_PLAYERS];

    printf("Olá! Bem-vindo ao programa E-Sports.\n");
    printf("1. Registrar jogador\n");
    printf("2. Imprimir jogador\n");
    printf("3. Alterar jogador\n");
    printf("4. Alterar pontuação\n");
    printf("5. Listar jogadores por nome\n");
    printf("6. Listar jogadores por Ranking\n");
    printf("7. Listar jogadores por No de vitórias\n");
    printf("8. Listar tabela de classificação\n");
    printf("9. Listar jogadores >\n");
    printf("10. Listar jogadores <\n");
    printf("11. Procurar jogador por nome\n");
    printf("12. Procurar jogador por ranking\n");
    printf("13. Média de seguidores de um jogador\n");

    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        criarJogador(jogadores);
        break;
    case 2:
        imprimirJogador(jogadores);
        break;
    case 3:
        alterarJogador(jogadores);
        break;
    case 4:
        alterarPosicao(jogadores);
        break;
    case 5:
        listarJogadoresPorNome();
        break;
    case 6:
        listarJogadoresPorRank();
        break;
    case 7:
        listarJogadoresPorVitoria();
        break;
    case 8:
        mostrarClassificacao();
        break;
    case 9:
        printf("Digite a pontuação desejada: ");
        scanf("%d", &valorPontuacao);
        listarJogadoresPontuacaoMaior(valorPontuacao);
        break;
    case 10:
        printf("Digite a pontuação desejada: ");
        scanf("%d", &valorPontuacao);
        listarJogadoresPontuacaoMenor(valorPontuacao);
        break;
    case 11: 
        printf("Digite o nome do jogador: ");
        scanf("%s", nomeJogador);
        exibirJogadorPorNome(nomeJogador);
        break;
    case 12: 
        printf("Digite o rank do jogador: ");
        int rankJogador;
        scanf("%d", &rankJogador);
        exibirJogadorPorRank(rankJogador);
        break;
    case 13:
        printf("Digite o nome do jogador: ");
        scanf("%s", nomeJogador);
        calcularMediaSeguidoresPorJogador(nomeJogador);
        break;
    default:
        printf("Opção inválida.\n");
    }

    system("pause");
    return 0;
}
