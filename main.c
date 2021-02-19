#include "main.h"

int main()
{
  int dificuldadeEscolhida, tamTabuleiro, **tabuleiro, **tabuleiroEspelho;
  char GAME_STATE = PLAYING;

  introducao();
  scanf("%i", &dificuldadeEscolhida);

  if (dificuldadeEscolhida == FACIL)
  {
    tamTabuleiro = 8;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    tamTabuleiro = 10;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    tamTabuleiro = 20;
  }
  else
  {
    exit(0);
  }

  tabuleiro = criarTabuleiro(tamTabuleiro);
  tabuleiroEspelho = criarTabuleiro(tamTabuleiro);

  popularTabuleiro(tabuleiro, tamTabuleiro);
  popularTabuleiro(tabuleiroEspelho, tamTabuleiro);
  sortearMinas(tabuleiro, tamTabuleiro);
  verificarCasasAdjacentes(tabuleiro, tamTabuleiro);

  /* GAME LOOP */
  while (GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, elemento;

    draw(tabuleiro, tamTabuleiro, tabuleiroEspelho);
    puts("Selecione a linha e coluna desejadas no formato [i j]");
    scanf("%i %i", &linha, &coluna);

    if ((linha < 0 || coluna < 0) ||                       // menor do que o tabuleiro
        (linha >= tamTabuleiro || coluna >= tamTabuleiro)) // maior do que o tabuleiro
    {
      tratarMensagemDeError("Casa nao existente");
      continue;
    }

    elemento = tabuleiro[linha][coluna];

    if (elemento == BOMBA)
    {
      printf("\033[0;31m");
      puts("Kaboooom ! Voce acertou uma bomba ! Game Over");
      printf("\033[0m");
      GAME_STATE = GAME_OVER;
    }
    else
    {
      tabuleiroEspelho[linha][coluna] = 1;
      /* Revelar as casas adjacentes */
    }
  }

  return 0;
}
