#include "menuScene.h"

void renderMenuScene(void)
{
  int dificuldadeEscolhida;

  /* Função para mostrar a tela inicial do jogo */
  introducao();

  /* Escolhendo e setando dificuldade do jogo */
  scanf("%i", &dificuldadeEscolhida);
  do
  {
  } while (getchar() != '\n');

  if (dificuldadeEscolhida == FACIL)
  {
    Jogo.dificuldade = Facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    Jogo.dificuldade = Medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    Jogo.dificuldade = Dificil;
  }
  else
  {
    exit(0);
  }

  Jogo.tabuleiro = criarTabuleiro();
}