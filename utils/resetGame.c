#include "resetGame.h"

void resetGame(void)
{
  Jogo.casasAbertas = 0;
  Jogo.numJogadas = 0;
  sortearMinas();
  verificarCasasAdjacentes();
}