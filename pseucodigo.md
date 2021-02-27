# Pseucodigo em linguagem natural
## Para Jogo Campo Minado

### Mapeamento inicial
1. Perguntar qual a dificuldade
2. Definir o tamanho do tabuleiro de acordo com a dificuldade
3. Definir posição das Minas
4. Enquanto o jogo estiver rodando, faça:
   1. Desenha o tabuleiro
   2. Realizar o lógica do nosso jogo

## Todo:

### Lógica:
TODO: Transformar as casas em objetos

### Estrutura do Jogo

struct Game{
  char nome[50];
  Dificuldade dificuldade;
  Tabuleiro tabuleiro[][];
  int linhaSelecionada;
  int colunaSelecionada;
}

struct Dificuldade{
  int facil;
  int medio;
  int dificil;
}

DIFICULDADE Opcoes = {1, 2, 3}

Game.dificuldade = Opcoes.facil;

struct Tabuleiro{
  int *tabuleiro;
  int *espelho;
  int tamanho;
}

### Estilo:
TODO: Pesquisar como alterar os caracteres de ASCII para UTF-8
