#ifndef DEFS_H
#define DEFS_H

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define PLAYING 1
#define GAME_OVER 2
#define BOMBA -1
#define SEM_BOMBA 0
#define CASA_MARCADA -1
#define CASA_FECHADA 0
#define CASA_ABERTA 1

typedef struct 
{
  int tam;
  int nMinas;
} DIFICULDADE;

typedef struct 
{
  DIFICULDADE dificuldade;
  int **jogavel;
  int **espelho;
  int casasAbertas;
} TABULEIRO;

#endif