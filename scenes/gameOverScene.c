#include "gameOverScene.h"

void renderGameOverScene(void)
{
  char op = 'S';

  popularMatrizCom(1, Jogo.tabuleiro.espelho);
  desenharTabuleiro();
  
  printf("\033[0;31m");
  printf("Kaboooom! Voce acertou uma bomba! Game Over.\n");
  printf("\033[0m");

  printf("Deseja continuar jogando ? (S/n)");
  scanf(" %c", &op);

  if (op == 'N' || op == 'n')
  {
    Jogo.GAME_STATE = EXIT;
  }
  else
  {
    renderMenuScene();
    resetGame();
    Jogo.GAME_STATE = PLAYING;
  }
}