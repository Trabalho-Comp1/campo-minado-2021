void sortearMinas(TABULEIRO tabuleiro)
{
  int linha, coluna, contador = 0;
  const int numeroMinas = tabuleiro.dificuldade.nMinas, tamTabuleiro = tabuleiro.dificuldade.tam;
  srand(time(0));

  while (contador < numeroMinas)
  {
    for (linha = 0; linha < tamTabuleiro && contador < numeroMinas; linha++)
    {
      for (coluna = 0; coluna < tamTabuleiro; coluna++)
      {
        const int random = rand() % 11;

        if (contador > numeroMinas)
        {
          break;
        }

        if (random <= 3 && contador < numeroMinas)
        {
          tabuleiro.jogavel[linha][coluna] = BOMBA;
          contador++;
        }
      }
    }
  }
}