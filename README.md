# Super Trunfo – Países (C)

Jogo em C no estilo Super Trunfo, tema **Países**, com 12 cartas pré-cadastradas.  
Modo **melhor de 5 rodadas**, **sem repetir cartas** já usadas, **placar acumulado** por partida e **opção de jogar novamente**.

## 🎮 Regras resumidas
- Cada rodada, dois jogadores escolhem cartas diferentes (não é permitido repetir cartas usadas).
- A comparação considera:
  - **População**: maior vence
  - **Área**: maior vence
  - **PIB**: maior vence
  - **Pontos turísticos**: maior vence
  - **Densidade populacional**: **menor** vence
  - **PIB per capita**: maior vence
  - **Super Poder** (soma simples das propriedades): maior vence
- Quem vencer mais atributos na rodada, ganha a rodada.
- A partida é **melhor de 5**.
- Ao final, você pode **jogar novamente**; o **placar geral** soma vitórias de partidas.

## 🚀 Como compilar e executar

### Pré-requisito
Ter o **gcc** instalado.

- **Windows**: instale o [MinGW-w64] ou use o WSL (Ubuntu).
- **Linux/macOS**: gcc geralmente já disponível (ou instale via gerenciador de pacotes).

### Compilar
```bash
gcc -o supertrunfo main.c


