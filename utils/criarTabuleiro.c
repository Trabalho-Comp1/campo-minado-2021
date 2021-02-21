TABULEIRO criarTabuleiro(DIFICULDADE dificuldade)
{
  int i, tamanho;
  TABULEIRO temp;

  temp.dificuldade = dificuldade;
  tamanho = temp.dificuldade.tam;

  temp.jogavel = (int **)malloc(tamanho * sizeof(int *));
  temp.espelho = (int **)malloc(tamanho * sizeof(int *));

  for (i = 0; i < tamanho; i++)
  {
    *(temp.jogavel+i) = calloc(tamanho, sizeof(int));
    *(temp.espelho+i) = calloc(tamanho, sizeof(int));
  }
  return temp;
}