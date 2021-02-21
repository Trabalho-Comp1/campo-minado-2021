void draw(TABULEIRO tabuleiro)
{
  int linha, coluna;
  system("cls");
  for (linha = -1; linha < tabuleiro.dificuldade.tam; linha++)
  {
    if (linha == -1)
    {
      printf("\t");
    }
    else
    {
      printf("%i\t", linha);
    }

    for (coluna = 0; coluna < tabuleiro.dificuldade.tam; coluna++)
    {
      if (linha == -1)
      {
        printf(" %i\t", coluna);
        continue;
      }

      if (tabuleiro.espelho[linha][coluna] == 0)
      {
        printf("[X]\t");
      }
      else
      {
        printf("[%i]\t", tabuleiro.jogavel[linha][coluna]);
      }
    }
    printf("\n");
  }
}