#include <stdio.h>
#include <string.h>

// Estrutura de uma carta
typedef struct {
    char codigo[4];
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    int usada; // 0 = disponível, 1 = já jogou
} Carta;

// Funções auxiliares
float densidade(Carta c) {
    return c.populacao / c.area;
}

float pibPerCapita(Carta c) {
    return c.pib * 1000000000 / c.populacao;
}

float superPoder(Carta c) {
    return c.populacao + c.area + c.pib + c.pontos_turisticos;
}

void mostrarCarta(Carta c) {
    printf("\n=== %s - %s ===\n", c.codigo, c.nome);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade(c));
    printf("PIB per Capita: %.2f\n", pibPerCapita(c));
    printf("Super Poder: %.2f\n", superPoder(c));
}

// Comparação de duas cartas → retorna 1 se c1 venceu, 2 se c2 venceu
int compararCartas(Carta c1, Carta c2) {
    int pontos1 = 0, pontos2 = 0;

    if (c1.populacao > c2.populacao) pontos1++; else pontos2++;
    if (c1.area > c2.area) pontos1++; else pontos2++;
    if (c1.pib > c2.pib) pontos1++; else pontos2++;
    if (c1.pontos_turisticos > c2.pontos_turisticos) pontos1++; else pontos2++;
    if (densidade(c1) < densidade(c2)) pontos1++; else pontos2++;
    if (pibPerCapita(c1) > pibPerCapita(c2)) pontos1++; else pontos2++;
    if (superPoder(c1) > superPoder(c2)) pontos1++; else pontos2++;

    printf("\nResultado da comparacao: %d x %d\n", pontos1, pontos2);
    return (pontos1 > pontos2) ? 1 : 2;
}

int main() {
    int jogarNovamente;
    int vitoriasJogador1 = 0, vitoriasJogador2 = 0; // placar acumulado

    do {
        // Reinicia cartas
        Carta cartas[12] = {
            {"A01", "Brasil",        214000000, 8515767, 2200, 15, 0},
            {"A02", "Argentina",      46000000, 2780000, 640,  10, 0},
            {"B01", "Japao",         125000000, 377975,  5000, 20, 0},
            {"B02", "EUA",           331000000, 9834000, 25000,25, 0},
            {"C01", "Franca",         67000000, 643801,  3200, 18, 0},
            {"C02", "Alemanha",       83000000, 357386,  4200, 16, 0},
            {"D01", "Mexico",        126000000,1964000,  1200, 12, 0},
            {"D02", "Canada",         38000000,9985000,  2000, 14, 0},
            {"E01", "Italia",         60000000, 301340,  2000, 17, 0},
            {"E02", "Espanha",        47000000, 505990,  1800, 13, 0},
            {"F01", "China",        1410000000,9597000, 18000, 22, 0},
            {"F02", "India",        1390000000,3287000,  9500, 19, 0}
        };

        int escolha1, escolha2;
        int pontosJogador1 = 0, pontosJogador2 = 0;

        printf("\n=== Super Trunfo - Paises (Melhor de 5) ===\n");

        for (int rodada = 1; rodada <= 5; rodada++) {
            printf("\n--- Rodada %d ---\n", rodada);

            // Mostrar cartas disponíveis
            for (int i = 0; i < 12; i++) {
                if (!cartas[i].usada) {
                    printf("%d - %s (%s)\n", i+1, cartas[i].nome, cartas[i].codigo);
                }
            }

            // Jogador 1 escolhe
            do {
                printf("Jogador 1, escolha sua carta: ");
                scanf("%d", &escolha1);
            } while (cartas[escolha1-1].usada);

            cartas[escolha1-1].usada = 1;

            // Jogador 2 escolhe
            do {
                printf("Jogador 2, escolha sua carta: ");
                scanf("%d", &escolha2);
            } while (cartas[escolha2-1].usada);

            cartas[escolha2-1].usada = 1;

            Carta c1 = cartas[escolha1-1];
            Carta c2 = cartas[escolha2-1];

            mostrarCarta(c1);
            mostrarCarta(c2);

            int vencedor = compararCartas(c1, c2);
            if (vencedor == 1) {
                printf("\n>>> Jogador 1 venceu a rodada!\n");
                pontosJogador1++;
            } else {
                printf("\n>>> Jogador 2 venceu a rodada!\n");
                pontosJogador2++;
            }
        }

        // Resultado da partida
        printf("\n=== Resultado Final da Partida ===\n");
        printf("Jogador 1: %d vitorias\n", pontosJogador1);
        printf("Jogador 2: %d vitorias\n", pontosJogador2);

        if (pontosJogador1 > pontosJogador2) {
            printf("\n>>> Jogador 1 venceu a partida!\n");
            vitoriasJogador1++;
        } else {
            printf("\n>>> Jogador 2 venceu a partida!\n");
            vitoriasJogador2++;
        }

        // Placar acumulado
        printf("\n=== Placar Geral ===\n");
        printf("Jogador 1: %d partidas vencidas\n", vitoriasJogador1);
        printf("Jogador 2: %d partidas vencidas\n", vitoriasJogador2);

        // Perguntar se quer jogar de novo
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &jogarNovamente);

    } while (jogarNovamente == 1);

    printf("\n=== Placar Final ===\n");
    printf("Jogador 1: %d partidas vencidas\n", vitoriasJogador1);
    printf("Jogador 2: %d partidas vencidas\n", vitoriasJogador2);

    if (vitoriasJogador1 > vitoriasJogador2)
        printf("\n>>> Jogador 1 foi o grande campeao!\n");
    else if (vitoriasJogador2 > vitoriasJogador1)
        printf("\n>>> Jogador 2 foi o grande campeao!\n");
    else
        printf("\n>>> O jogo terminou empatado!\n");

    printf("\nObrigado por jogar! Ate a proxima!\n");
    return 0;
}
