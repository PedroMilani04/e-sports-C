#ifndef JOGADORES_H
#define JOGADORES_H

#include <stdio.h>

#define MAX_PLAYERS 50
#define MAX_NAME_LENGTH 50

// Estruturas e definições de tipos aqui...
typedef struct equipe
{
    char nome[50];
    char nick[50];
    int seguidores;
} EQUIPE;

typedef struct hardware
{
    char computador[50];
    char processador[50];
    char placadevideo[50];
    int RAM;
} HARDWARE;

typedef struct campeonato
{
    int pontuacao;
    int vitorias;
    int derrotas;
    int empates;
} CAMPEONATO;

typedef struct jogador
{
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


// Declarações de funções
void criarJogador(JOGADOR players[]);
int compararClassificacao(const void *a, const void *b);
void mostrarClassificacao();
void exibirJogador(JOGADOR *a);
void imprimirJogador(JOGADOR players[]);
void alterarJogador(JOGADOR players[]);
void alterarPosicao(JOGADOR players[]);
int compararNomes(const void *a, const void *b);
void listarJogadoresPorNome();
int compararRanks(const void *a, const void *b);
void listarJogadoresPorRank();
int compararVitorias(const void *a, const void *b);
void listarJogadoresPorVitoria();
void listarJogadoresPontuacaoMaior(int valorPontuacao);
void listarJogadoresPontuacaoMenor(int valorPontuacao);
void exibirJogadorPorNome(const char *nome);
void exibirJogadorPorRank(int rank);
float calcularMediaSeguidoresPorJogador(const char *nome);

#endif // JOGADORES_H

