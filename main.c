#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  int dificuldadeEscolhida;
  char GAME_STATE = PLAYING;

  DIFICULDADE dificuldade;
  TABULEIRO tabuleiro;

  puts("==== JOGO DO CAMPO DO MINADO ====");
  puts("Desenvolvido por: Abid Lohan, Diego Matos e Lia Barcellos");
  puts("=======================================");
  puts("Escolha a dificuldade do jogo:");
  puts("[1] - Facil, [2] - Medio, [3] - Dificil, [4] - SAIR");
  scanf("%i", &dificuldadeEscolhida);

  if (dificuldadeEscolhida == FACIL)
  {
    dificuldade = facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    dificuldade = medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    dificuldade = dificil;
  }
  else
  {
    exit(0);
  }

  tabuleiro.jogavel = criarTabuleiro(dificuldade.tam);
  tabuleiro.espelho = criarTabuleiro(dificuldade.tam);

  popularTabuleiro(tabuleiro.jogavel, dificuldade.tam);
  popularTabuleiro(tabuleiro.espelho, dificuldade.tam);
  sortearMinas(tabuleiro.jogavel, dificuldade);
  verificarCasasAdjacentes(tabuleiro.jogavel, dificuldade.tam);

  /* GAME LOOP */
  while (GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, elemento;

    draw(tabuleiro.jogavel, dificuldade.tam, tabuleiro.espelho);
    puts("Selecione a linha e coluna desejadas no formato [i j]");
    scanf("%i %i", &linha, &coluna);

    if ((linha < 0 || coluna < 0) ||                       // menor do que o tabuleiro
        (linha >= dificuldade.tam || coluna >= dificuldade.tam)) // maior do que o tabuleiro
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
    else
    {
      tabuleiro.espelho[linha][coluna] = 1;
      /* Revelar as casas adjacentes */
    }
  }

  return 0;
}
