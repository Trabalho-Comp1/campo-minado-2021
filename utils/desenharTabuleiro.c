void desenharTabuleiro()
{
  int linha, coluna;
  system("cls");
  
  for (linha = -1; linha < Jogo.dificuldade.tam; linha++)
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

    for (coluna = 0; coluna < Jogo.dificuldade.tam; coluna++)
    {
      if (linha == -1)
      {
        printf("\033[1m");
        printf(" %i\t", coluna);
        printf("\033[0m");
        continue;
      }

      if (Jogo.tabuleiro.espelho[linha][coluna] == 0)
      {
        printf("[X]\t");
      }
      else if(Jogo.tabuleiro.espelho[linha][coluna] == -1){
        printf("[M]\t");
      }
      else
      {
        printf("[%i]\t", Jogo.tabuleiro.jogavel[linha][coluna]);
      }
    }
    printf("\n");
  }
}