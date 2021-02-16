void draw(int **tabuleiro, int tamTabuleiro, int **tabuleiroEspelho)
{
  int linha, coluna;
  system("cls");
  /* system("clear"); */
  for (linha = 0; linha < tamTabuleiro; linha++)
  {
    if (linha == -1)
    {
      printf("\t");
    }
    else
    {
      printf("%i\t", linha);
    }

    for (coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      if (linha == -1)
      {
        printf(" %i\t", coluna);
        continue;
      }

      if (tabuleiroEspelho[linha][coluna] == 0)
      {
        /* printf("[%i, %i]\t", linha, coluna); */
        printf("[X]\t");
      }
      else
      {
        /* printf("[  %i  ]\t", tabuleiro[linha][coluna]); */
        printf("[%i]\t", tabuleiro[linha][coluna]);
      }
    }
    printf("\n");
  }
}
