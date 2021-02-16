void sortearMinas(int **tabuleiro, DIFICULDADE dificuldade)
{
  int contador = 0;
  const int numeroMinas = dificuldade.nMinas;
  srand(time(0));

  while (contador < numeroMinas)
  {
    for (int linha = 0; linha < dificuldade.tam && contador < numeroMinas; linha++)
    {
      for (int coluna = 0; coluna < dificuldade.tam; coluna++)
      {
        const int random = rand() % 11;

        if (contador > numeroMinas)
        {
          break;
        }

        if (random <= 3 && contador < numeroMinas)
        {
          tabuleiro[linha][coluna] = BOMBA;
          contador++;
        }
      }
    }
  }
}