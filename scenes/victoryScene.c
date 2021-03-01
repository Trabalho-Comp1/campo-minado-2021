#include "victoryScene.h"

void renderVictoryScene(void)
{
  char op = 'S';

  /* Revelar todas as casas */
  popularMatrizCom(1, Jogo.tabuleiro.espelho);
  desenharTabuleiro();

  printf("\033[0;32m");
  wprintf(L"Parabéns! Você ganhou o jogo!\n");
  printf("\033[0m");

  wprintf(L"Deseja continuar jogando ? (S/n)");
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