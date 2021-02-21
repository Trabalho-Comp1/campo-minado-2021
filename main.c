#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  int dificuldadeEscolhida, casasAbertas = 0;
  char GAME_STATE = PLAYING;

  TABULEIRO tabuleiro;

  introducao();

  scanf("%i", &dificuldadeEscolhida);
  if (dificuldadeEscolhida == FACIL)
  {
    tabuleiro.dificuldade = facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    tabuleiro.dificuldade = medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    tabuleiro.dificuldade = dificil;
  }
  else
  {
    exit(0);
  }

  tabuleiro = criarTabuleiro(tabuleiro.dificuldade);
  popularTabuleiro(tabuleiro);
  sortearMinas(tabuleiro);
  verificarCasasAdjacentes(tabuleiro);
  
  /* GAME LOOP */
  while (GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, elemento;

    draw(tabuleiro);
    puts("Selecione a linha e coluna desejadas no formato [i j]");
    scanf("%i %i", &linha, &coluna);

    if ((linha < 0 || coluna < 0) ||                       /* menor do que o tabuleiro */
        (linha >= tabuleiro.dificuldade.tam || coluna >= tabuleiro.dificuldade.tam)) /* maior do que o tabuleiro */
    {
      tratarMensagemDeError("Casa nao existente");
      continue;
    }

    elemento = tabuleiro.jogavel[linha][coluna];

    if (elemento == BOMBA)
    {
      popularMatrizCom(1, tabuleiro.espelho, tabuleiro.dificuldade.tam);
      draw(tabuleiro);
      printf("\033[0;31m");
      puts("Kaboooom ! Voce acertou uma bomba ! Game Over");
      printf("\033[0m");
      GAME_STATE = GAME_OVER;
    }

    /* Continuar lógica para liberar os 0s */
    else if (elemento == 0){
      tabuleiro.espelho[linha][coluna] = 1;
      revelarCasas(tabuleiro, linha, coluna);
    }
    else
    {
      tabuleiro.espelho[linha][coluna] = 1;
      casasAbertas++;

      /* Caso todas as casas forem abertas, menos as que conterem bombas => vitória */
      if(casasAbertas == tabuleiro.dificuldade.tam*tabuleiro.dificuldade.tam - tabuleiro.dificuldade.nMinas){
          puts("Parabens! Voce ganhou o jogo!");
          GAME_STATE = GAME_OVER;
      }
    }
  }

  return 0;
}