#ifndef DEFS_H
#define DEFS_H

#define FACIL 0
#define MEDIO 1
#define DIFICIL 2
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
} TABULEIRO;

#endif