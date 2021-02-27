void draw(TABULEIRO tabuleiro)
{
  int linha, coluna;
  printf("\033[1;1H\033[2J"); /*Limpar terminal (teoricamente funciona Linux/Win)*/
  
  for (linha = -1; linha < tabuleiro.dificuldade.tam; linha++)
  {
    if (linha == -1)
    {
      printf("\t");
    }
    else
    {
      printf("\033[1m");
      printf(" %i\t", linha);
      printf("\033[0m");
    }

    for (coluna = 0; coluna < tabuleiro.dificuldade.tam; coluna++)
    {
      if (linha == -1)
      {
        printf("\033[1m");
        printf(" %i\t", coluna);
        printf("\033[0m");
        continue;
      }

      if (tabuleiro.espelho[linha][coluna] == 0)
      {
        printf("[X]\t");
      }
      else if(tabuleiro.espelho[linha][coluna] == -1){
        printf("[M]\t");
      }
      else
      {
        printf("[%i]\t", tabuleiro.jogavel[linha][coluna]);
      }
    }
    printf("\n");
  }
}