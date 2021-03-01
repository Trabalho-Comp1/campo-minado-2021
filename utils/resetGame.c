#include "../utils/sortearMinas.c"
#include "../utils/verificarCasasAdjacentes.c"

void resetGame(void)
{
  sortearMinas();
  verificarCasasAdjacentes();
}