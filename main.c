#include <stdio.h>
#include <stdlib.h>
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

/*
Tabuleiro: 
x - casa nao aberta
0 - casa aberta sem bomba em volta
N - casa aberta com N bombas em volta

Acompanhamento:
0 - Casa aberta
1 - Casa aberta
*/

char **criarTabuleiro(int tamanho);

int main()
{
  int dificuldadeEscolhida, tamTabuleiro;
  unsigned int i, j;
  char **tabuleiro;
  /* int **controleTabuleiro; */

  puts("=== JOGO DO CAMPO DO MINADO ===");
  puts("Qual a dificuldade do jogo?");
  puts("[1] - Facil, [2] - Medio, [3] - Dificil, [4] - SAIR");
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

  /* Popular o tabuleiro */
  for (i = 0; i < tamTabuleiro; i++)
  {
    for (j = 0; j < tamTabuleiro; j++)
    {
      /* TODO: Definir as Minas */
      tabuleiro[i][j] = '0';
    }
  }

  /* GAME LOOP */

    /* Desenhar o tabuleiro */
    for (i = 0; i < tamTabuleiro; i++)
    {
      for (j = 0; j < tamTabuleiro; j++)
      {
        printf("%c", tabuleiro[i][j]);
      }
      printf("\n");
    }

  return 0;
}

char **criarTabuleiro(int tamanho)
{
  char **tabuleiro;
  tabuleiro = (char **)malloc(tamanho * sizeof(char *));
  
  for (int i = 0; i < tamanho; i++)
  {
    tabuleiro[i] = (char *)malloc(tamanho * sizeof(char *));
  }

  return tabuleiro;
}