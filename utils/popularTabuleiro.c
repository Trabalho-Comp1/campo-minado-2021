void popularTabuleiro(int **tabuleiro, int tamTabuleiro)
{
  int linha, coluna;
  for (linha = 0; linha < tamTabuleiro; linha++)
  {
    for (coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      tabuleiro[linha][coluna] = 0;
    }
  }
}