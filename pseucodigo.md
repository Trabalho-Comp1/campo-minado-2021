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

TODO: Criar função para popular o tabuleiro

TODO: Criar função para desenhar o tabuleiro 

TODO: Criar game loop

```
struct Game{
  int dificuldade;
  int tabuleiro[][];
  void* init;
  void* draw;
  void* update;
}
```