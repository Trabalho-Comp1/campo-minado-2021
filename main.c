#include "main.h"

int main()
{
  int dificuldadeEscolhida, tamTabuleiro, **tabuleiro, **tabuleiroEspelho;
  int casasAbertas = 0;
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

    /* Continuar lógica para liberar os 0s */
    else if (elemento == CASA_LIVRE){
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                tabuleiroEspelho[i][j] = 1;
            }
        }
    }

    else
    {
      tabuleiroEspelho[linha][coluna] = 1;
      casasAbertas++;

      /* Caso todas as casas forem abertas, menos as que conterem bombas => vitória */
      if(casasAbertas == tamTabuleiro*tamTabuleiro - (tamTabuleiro*tamTabuleiro)/5){
          puts("Parabens! Voce ganhou o jogo!");
          GAME_STATE = GAME_OVER;
      }

      /* Revelar as casas adjacentes */
    }
  }

  return 0;
}
