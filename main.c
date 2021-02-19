#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  int dificuldadeEscolhida;
  char GAME_STATE = PLAYING;
  int casasAbertas = 0;

  DIFICULDADE dificuldade;
  TABULEIRO tabuleiro;

  introducao();
  scanf("%i", &dificuldadeEscolhida);

  if (dificuldadeEscolhida == FACIL)
  {
    /* dificuldade = facil; */
    tabuleiro.dificuldade = facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    /* dificuldade = medio; */
    tabuleiro.dificuldade = medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    /* dificuldade = dificil; */
    tabuleiro.dificuldade = dificil;
  }
  else
  {
    exit(0);
  }

  tabuleiro.jogavel = criarTabuleiro(tabuleiro.dificuldade.tam);
  tabuleiro.espelho = criarTabuleiro(tabuleiro.dificuldade.tam);

  popularTabuleiro(tabuleiro.jogavel, tabuleiro.dificuldade.tam);
  popularTabuleiro(tabuleiro.espelho, tabuleiro.dificuldade.tam);
  sortearMinas(tabuleiro.jogavel, tabuleiro.dificuldade);
  verificarCasasAdjacentes(tabuleiro.jogavel, tabuleiro.dificuldade.tam);

  /* GAME LOOP */
  while (GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, elemento;

    draw(tabuleiro.jogavel, tabuleiro.dificuldade.tam, tabuleiro.espelho);
    puts("Selecione a linha e coluna desejadas no formato [i j]");
    scanf("%i %i", &linha, &coluna);

    if ((linha < 0 || coluna < 0) ||                       // menor do que o tabuleiro
        (linha >= tabuleiro.dificuldade.tam || coluna >= tabuleiro.dificuldade.tam)) // maior do que o tabuleiro
    {
      tratarMensagemDeError("Casa nao existente");
      continue;
    }

    elemento = tabuleiro.jogavel[linha][coluna];

    if (elemento == BOMBA)
    {
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
      if(casasAbertas == tabuleiro.dificuldade.tam*tabuleiro.dificuldade.tam - (tabuleiro.dificuldade.tam*dificuldade.tam)/5){
          puts("Parabens! Voce ganhou o jogo!");
          GAME_STATE = GAME_OVER;
      }
    }
  }

  return 0;
}