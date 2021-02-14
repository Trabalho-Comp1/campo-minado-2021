void verificarCasasAdjacentes(int **tabuleiro, int tamTabuleiro)
{
  for (int linha = 0; linha < tamTabuleiro; linha++)
  {
    for (int coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      unsigned int bombasProximas = 0;
      const int celulaCentral = tabuleiro[linha][coluna];

      if (celulaCentral == BOMBA)
      {
        continue;
      }

      for (int i = -1; i < 2; i++)
      {
        for (int j = -1; j < 2; j++)
        {
          if (
              (i == 0 && j == 0) ||                                     //proprio elemento
              (linha + i < 0 || coluna + j < 0) ||                      // menor do que o tabuleiro
              (linha + i >= tamTabuleiro || coluna + j >= tamTabuleiro) // maior que o tabuleiro
          )
          {
            continue;
          }
          if (tabuleiro[linha + i][coluna + j] == BOMBA)
          {
            bombasProximas++;
          }
        }
      }

      tabuleiro[linha][coluna] = bombasProximas;
    }
  }
}