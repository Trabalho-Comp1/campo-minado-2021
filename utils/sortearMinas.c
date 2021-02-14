void sortearMinas(int **tabuleiro, int tamTabuleiro)
{
  int contador = 0;
  const int numeroMinas = (tamTabuleiro * tamTabuleiro) / 5;
  srand(time(0));

  while (contador < numeroMinas)
  {
    for (int linha = 0; linha < tamTabuleiro && contador < numeroMinas; linha++)
    {
      for (int coluna = 0; coluna < tamTabuleiro; coluna++)
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