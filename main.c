#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct equipe{
    char nome[50];
    char nick[50];
    int seguidores;
} EQUIPE;

typedef struct hardware{
    char computador[50];
    char processador[50];
    char placadevideo[50];
    int RAM;
} HARDWARE;

typedef struct campeonato{
    int pontuacao;
    int vitorias;
    int derrotas;
    int empates;
} CAMPEONATO;

typedef struct jogador{
    char nome[50];
    char nasc[10];
    char CPF[14];
    char genero[50];
    char estadocivil[50];
    EQUIPE equipe;
    char patrocinio[50];
    char nick[50];
    int numeroseg;
    HARDWARE hardware;
    CAMPEONATO campeonato;
    int titulos;
    int rank;
} JOGADOR;



void criarJogador(JOGADOR players[]) {
    printf("Registrar um jogador\n");
    printf("Numero do jogador: ");
    int n;
    scanf("%d", &n);
    printf("Nome: ");
    scanf("%s", players[n].nome);
    printf("Nascimento: ");
    scanf("%s", players[n].nasc);
    printf("CPF: ");
    scanf("%s", players[n].CPF);
    printf("Gênero: ");
    scanf("%s", players[n].genero);
    printf("Estado Civil: ");
    scanf("%s", players[n].estadocivil);
    printf("Nome da equipe: ");
    scanf("%s", players[n].equipe.nome);
    printf("Nick da equipe: ");
    scanf("%s", players[n].equipe.nick);
    printf("Número de seguidores da Equipe: ");
    scanf("%d", &players[n].equipe.seguidores);
    printf("Patrocinador: ");
    scanf("%s", players[n].patrocinio);
    printf("Nick do jogador: ");
    scanf("%s", players[n].nick);
    printf("Número de seguidores do Jogador: ");
    scanf("%d", &players[n].numeroseg);
    printf("Computador: ");
    scanf("%s", players[n].hardware.computador);
    printf("CPU: ");
    scanf("%s", players[n].hardware.processador);
    printf("GPU: ");
    scanf("%s", players[n].hardware.placadevideo);
    printf("RAM: ");
    scanf("%d", &players[n].hardware.RAM);
    printf("Pontuação de Campeonato: ");
    scanf("%d", &players[n].campeonato.pontuacao);
    printf("Vitórias de Campeonato: ");
    scanf("%d", &players[n].campeonato.vitorias);
    printf("Derrotas de Campeonato: ");
    scanf("%d", &players[n].campeonato.derrotas);
    printf("Empates de Campeonato: ");
    scanf("%d", &players[n].campeonato.empates);
    printf("Número de Títulos: ");
    scanf("%d", &players[n].titulos);
    printf("Ranqueamento: ");
    scanf("%d", &players[n].rank);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;
    JOGADOR jogadores[50];

    printf("Olá! Bem-vindo ao programa E-Sports.\n");
    printf("1. Registrar jogador\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        criarJogador(jogadores);
        printf("%s", jogadores[0].nome);
        break;
    // Add more cases as needed

    default:
        printf("Opção inválida.\n");
    }

    system("pause");
    return 0;
}
