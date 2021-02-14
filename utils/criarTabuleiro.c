int **criarTabuleiro(int tamanho)
{
  int **tabuleiro;
  tabuleiro = (int **)malloc(tamanho * sizeof(int *));

  for (int i = 0; i < tamanho; i++)
  {
    tabuleiro[i] = (int *)malloc(tamanho * sizeof(int *));
  }

  return tabuleiro;
}