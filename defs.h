#ifndef DEFS_H
#define DEFS_H

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define EXIT -1
#define PLAYING 1
#define GAME_OVER 2
#define BOMBA -1
#define SEM_BOMBA 0
#define CASA_MARCADA -1
#define CASA_FECHADA 0
#define CASA_ABERTA 1

typedef struct _DIFICULDADE
{
  int tam;
  int nMinas;
} DIFICULDADE;

typedef struct _TABULEIRO
{
  int **jogavel;
  int **espelho;
} TABULEIRO;

/* Adicionar propriedade de pontuação */
typedef struct _GAME
{
  DIFICULDADE dificuldade;
  TABULEIRO tabuleiro;
  int GAME_STATE;
  unsigned int casasAbertas;
  unsigned int numJogadas;
} GAME;

#endif