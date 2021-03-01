#include "../utils/sortearMinas.c"
#include "../utils/verificarCasasAdjacentes.c"

void resetGame(void)
{
  Jogo.casasAbertas = 0;
  Jogo.numJogadas = 0;
  sortearMinas();
  verificarCasasAdjacentes();
}