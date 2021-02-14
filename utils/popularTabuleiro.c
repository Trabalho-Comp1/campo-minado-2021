void popularTabuleiro(int **tabuleiro, int tamTabuleiro)
{
  for (int linha = 0; linha < tamTabuleiro; linha++)
  {
    for (int coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      tabuleiro[linha][coluna] = 0;
    }
  }
}