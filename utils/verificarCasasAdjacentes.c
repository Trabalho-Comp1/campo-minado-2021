void verificarCasasAdjacentes()
{
  int linha, coluna, i, j;
  const int tamTabuleiro = Jogo.dificuldade.tam;

  for (linha = 0; linha < tamTabuleiro; linha++)
  {
    for (coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      unsigned int bombasProximas = 0;
      int *celulaCentral = &Jogo.tabuleiro.jogavel[linha][coluna];

      if (*celulaCentral == BOMBA)
      {
        continue;
      }

      for (i = -1; i < 2; i++)
      {
        for (j = -1; j < 2; j++)
        {
          if (
              (i == 0 && j == 0) ||                                     /* proprio elemento */
              (linha + i < 0 || coluna + j < 0) ||                      /* menor do que o tabuleiro */
              (linha + i >= tamTabuleiro || coluna + j >= tamTabuleiro) /* maior que o tabuleiro */
          )
          {
            continue;
          }
          if (Jogo.tabuleiro.jogavel[linha + i][coluna + j] == BOMBA)
          {
            bombasProximas++;
          }
        }
      }
      *celulaCentral = bombasProximas;
    }
  }
}