#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define PLAYING 1
#define GAME_OVER 2
#define BOMBA -1
#define CASA_LIVRE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./utils/criarTabuleiro.c"
#include "./utils/popularTabuleiro.c"
#include "./utils/sortearMinas.c"
#include "./utils/verificarCasasAdjacentes.c"
#include "./utils/draw.c"
#include "./utils/tratarMensagemDeError.c"