#include "main.h"

extern DIFICULDADE Facil, Medio, Dificil;

int main()
{
  int dificuldadeEscolhida;
  setlocale(LC_ALL, "Portuguese");
  fwide(stdout, 1);

  /* Função para mostrar a tela inicial do jogo */
  introducao();
  
  /* Escolhendo e setando dificuldade do jogo */
  scanf("%i", &dificuldadeEscolhida);
  do{} while (getchar() != '\n');

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

  /* Iniciando o jogo */
  Jogo.tabuleiro = criarTabuleiro();
  sortearMinas();
  verificarCasasAdjacentes();
  Jogo.GAME_STATE = PLAYING;

  /* GAME LOOP */
  while (Jogo.GAME_STATE != EXIT)
  {
    if(Jogo.GAME_STATE == PLAYING)
    {
      renderGameScene();
    }
    else if (Jogo.GAME_STATE == GAME_OVER)
    {
      /* renderGameOverScene(); */
    }
  }

  return 0;
}