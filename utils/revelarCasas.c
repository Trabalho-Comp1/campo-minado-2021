void revelarCasas(int linha, int coluna)
{
  int i, j, casaAtual, casaAtualEspelho;
  for (i = -1; i < 2; i++)
  {
    for (j = -1; j < 2; j++)
    {
      if (
          (i == 0 && j == 0) ||                                     /*proprio elemento*/
          (linha + i < 0 || coluna + j < 0) ||                      /* menor do que o tabuleiro*/
          (linha + i >= Jogo.dificuldade.tam || coluna + j >= Jogo.dificuldade.tam) /* maior que o tabuleiro */
      )
      {
        continue;
      }
      casaAtual = Jogo.tabuleiro.jogavel[linha + i][coluna + j];
      casaAtualEspelho = Jogo.tabuleiro.espelho[linha + i][coluna + j];

      if(casaAtualEspelho == CASA_ABERTA){
          continue;
      }
      
      if (casaAtual >= SEM_BOMBA)
      {
        Jogo.casasAbertas++;
        Jogo.tabuleiro.espelho[linha + i][coluna + j] = CASA_ABERTA;
        
        if(casaAtual == SEM_BOMBA){
          revelarCasas(linha + i, coluna + j);
        }
      }
    }
  }
}