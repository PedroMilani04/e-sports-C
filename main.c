#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PLAYERS 50
#define MAX_NAME_LENGTH 50

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

void criarJogador(JOGADOR players[])
{
    printf("Registrar um jogador\n");
    printf("Número do jogador: ");
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

    FILE *file;
    file = fopen("jogadores.dat", "ab");

    if (file != NULL)
    {
        int qntRegEscritos = fwrite(&players[n], sizeof(JOGADOR), 1, file);
        printf("Foram escritos %d registros!\n", qntRegEscritos);
        fclose(file);
    }
    else
        printf("ARQUIVO FALHOU\n");

    return;
}

int compararClassificacao(const void *a, const void *b)
{
    const JOGADOR *jogadorA = (const JOGADOR *)a;
    const JOGADOR *jogadorB = (const JOGADOR *)b;

    // compara por pontuacao, se for igual, compara por vitoria, se for igual, por derrota, e se for igual dnv, por empate

    if (jogadorA->campeonato.pontuacao != jogadorB->campeonato.pontuacao)
        return jogadorB->campeonato.pontuacao - jogadorA->campeonato.pontuacao;

    if (jogadorA->campeonato.vitorias != jogadorB->campeonato.vitorias)
        return jogadorB->campeonato.vitorias - jogadorA->campeonato.vitorias;

    if (jogadorA->campeonato.derrotas != jogadorB->campeonato.derrotas)
        return jogadorA->campeonato.derrotas - jogadorB->campeonato.derrotas;

    return jogadorB->campeonato.empates - jogadorA->campeonato.empates;
}

void mostrarClassificacao()
{
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);

    // Sort players by classification criteria
    qsort(jogadores, numPlayers, sizeof(JOGADOR), compararClassificacao);

    // Display the classification in a simpler format
    printf("%-4s %-20s %-5s %-8s %-8s %-8s %-8s\n", "Pos.", "Nome", "Rank", "Pontos", "Vitórias", "Derrotas", "Empates");

    for (int i = 0; i < numPlayers; i++)
    {
        printf("%-4d %-20s %-5d %-8d %-8d %-8d %-8d\n", i + 1, jogadores[i].nome, jogadores[i].rank,
               jogadores[i].campeonato.pontuacao, jogadores[i].campeonato.vitorias,
               jogadores[i].campeonato.derrotas, jogadores[i].campeonato.empates);
    }

    free(jogadores);
    fclose(file);
}

void exibirJogador(JOGADOR *a)
{
    printf("Nome: %s\n", a->nome);
}

void imprimirJogador(JOGADOR players[])
{
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    int a;
    printf("Jogador a ser impresso: ");
    scanf("%d", &a);

    JOGADOR jogadorlido;
    fseek(file, a * sizeof(JOGADOR), SEEK_SET); // Move o ponteiro para a posição correta
    fread(&jogadorlido, sizeof(JOGADOR), 1, file);

    // Exibir diretamente sem a necessidade de outra função
    printf("Nome: %s\n", jogadorlido.nome);

    fclose(file);
}

void alterarJogador(JOGADOR players[])
{
    FILE *file;
    file = fopen("jogadores.dat", "rb+"); // Open in read and write mode

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    int a;
    printf("Jogador a ser alterado: ");
    scanf("%d", &a);

    JOGADOR jogadorAtualizado;
    fseek(file, a * sizeof(JOGADOR), SEEK_SET);
    fread(&jogadorAtualizado, sizeof(JOGADOR), 1, file);

    // Prompt for the field to be updated
    printf("Digite o novo nome do jogador: ");
    scanf("%s", jogadorAtualizado.nome);

    // Write the updated record back to the file
    fseek(file, a * sizeof(JOGADOR), SEEK_SET);
    fwrite(&jogadorAtualizado, sizeof(JOGADOR), 1, file);

    printf("Jogador alterado com sucesso!\n");

    fclose(file);
}

void alterarPosicao(JOGADOR players[])
{
    FILE *file;
    file = fopen("jogadores.dat", "rb+"); // Open in read and write mode

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    int a;
    printf("Jogador a ser alterado: ");
    scanf("%d", &a);

    JOGADOR jogadorAtualizado;
    fseek(file, a * sizeof(JOGADOR), SEEK_SET);
    fread(&jogadorAtualizado, sizeof(JOGADOR), 1, file);

    int opcao;
    int pont;
    printf("1. Vitória\n");
    printf("2. Derrota\n");
    printf("3. Empate\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Novas vitórias:");
        scanf("%d", &pont);
        jogadorAtualizado.campeonato.vitorias += pont;
        printf("Vitórias totais: %d", jogadorAtualizado.campeonato.vitorias);
        break;
    case 2:
        printf("Novas derrotas:");
        scanf("%d", &pont);
        jogadorAtualizado.campeonato.derrotas += pont;
        break;
    case 3:
        printf("Novos empates:");
        scanf("%d", &pont);
        jogadorAtualizado.campeonato.empates += pont;
        break;
    default:
        printf("");
    }

    // Write the updated record back to the file
    fseek(file, a * sizeof(JOGADOR), SEEK_SET);
    fwrite(&jogadorAtualizado, sizeof(JOGADOR), 1, file);

    fclose(file);
}
int compararNomes(const void *a, const void *b)
{
    return strcmp(((JOGADOR *)a)->nome, ((JOGADOR *)b)->nome);
}
void listarJogadoresPorNome()
{
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);

    // Sort players by name
    qsort(jogadores, numPlayers, sizeof(JOGADOR), compararNomes);

    // Print sorted names
    printf("Jogadores em ordem alfabética:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s\n", jogadores[i].nome);
    }

    free(jogadores);
    fclose(file);
}

int compararRanks(const void *a, const void *b)
{
    return ((JOGADOR *)a)->rank - ((JOGADOR *)b)->rank;
}

void listarJogadoresPorRank()
{
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);

    // Sort players by rank
    qsort(jogadores, numPlayers, sizeof(JOGADOR), compararRanks);

    // Print sorted ranks
    printf("Jogadores em ordem de ranking:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Rank: %d, Nome: %s\n", jogadores[i].rank, jogadores[i].nome);
    }

    free(jogadores);
    fclose(file);
}

int compararVitorias(const void *a, const void *b)
{
    return ((JOGADOR *)b)->campeonato.vitorias - ((JOGADOR *)a)->campeonato.vitorias;
}

void listarJogadoresPorVitoria()
{
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);

    // Sort players by victories
    qsort(jogadores, numPlayers, sizeof(JOGADOR), compararVitorias);

    // Print top 10 players with most victories
    int topPlayers = (numPlayers < 10) ? numPlayers : 10;
    printf("Top 10 jogadores com mais vitórias:\n");
    for (int i = 0; i < topPlayers; i++)
    {
        printf("Posição: %d, Vitórias: %d, Nome: %s\n", i + 1, jogadores[i].campeonato.vitorias, jogadores[i].nome);
    }

    free(jogadores);
    fclose(file);
}

void listarJogadoresPontuacaoMaior(int valorPontuacao)
{

    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);
    printf("Jogadores com pontuação maior que %d:\n", valorPontuacao);

    for (int i = 0; i < numPlayers; i++)
    {
        if (jogadores[i].campeonato.pontuacao > valorPontuacao)
        {
            printf("%s\n", jogadores[i].nome);
        }
    }
}


void listarJogadoresPontuacaoMenor(int valorPontuacao)
{

    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file == NULL)
    {
        printf("O ARQUIVO NÃO FOI ABERTO!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numPlayers = fileSize / sizeof(JOGADOR);

    JOGADOR *jogadores = malloc(numPlayers * sizeof(JOGADOR));

    fread(jogadores, sizeof(JOGADOR), numPlayers, file);
    printf("Jogadores com pontuação menor que %d:\n", valorPontuacao);

    for (int i = 0; i < numPlayers; i++)
    {
        if (jogadores[i].campeonato.pontuacao < valorPontuacao)
        {
            printf("%s\n", jogadores[i].nome);
        }
    }
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    int opcao, valorPontuacao;
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
    default:
        printf("Opção inválida.\n");
    }

    system("pause");
    return 0;
}