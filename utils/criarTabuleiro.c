int **criarTabuleiro(int tamanho)
{
  int i, **tabuleiro;
  tabuleiro = (int **)malloc(tamanho * sizeof(int *));

  for (i = 0; i < tamanho; i++)
  {
    tabuleiro[i] = (int *)malloc(tamanho * sizeof(int *));
  }

  return tabuleiro;
}