void revelarCasas(void)
{
  for (int i = -1; i < 2; i++)
  {
    for (int j = -1; j < 2; j++)
    {
      tabuleiro.espelho[i][j] = 1;
    }
  }
}