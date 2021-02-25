void revelarCasas(TABULEIRO *tabuleiro, int linha, int coluna)
{
  int i, j, casaAtual, casaAtualEspelho;
  for (i = -1; i < 2; i++)
  {
    for (j = -1; j < 2; j++)
    {
      if (
          (i == 0 && j == 0) ||                                     /*proprio elemento*/
          (linha + i < 0 || coluna + j < 0) ||                      /* menor do que o tabuleiro*/
          (linha + i >= tabuleiro->dificuldade.tam || coluna + j >= tabuleiro->dificuldade.tam) /* maior que o tabuleiro */
      )
      {
        continue;
      }
      casaAtual = tabuleiro->jogavel[linha + i][coluna + j];
      casaAtualEspelho = tabuleiro->espelho[linha + i][coluna + j];

      if(casaAtualEspelho == 1){
          continue;
      }
      
      tabuleiro->casasAbertas++;
      tabuleiro->espelho[linha + i][coluna + j] = 1;

      if (casaAtual == 0)
      {
        revelarCasas(tabuleiro, linha + i, coluna + j);
      }
    }
  }
}