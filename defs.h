#ifndef DEFS_H
#define DEFS_H

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define PLAYING 1
#define GAME_OVER 2
#define BOMBA -1
#define CASA_LIVRE 0

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