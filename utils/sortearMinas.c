void sortearMinas()
{
  int linha, coluna, contador = 0;
  const int numeroMinas = Jogo.dificuldade.nMinas, tamTabuleiro = Jogo.dificuldade.tam;
  srand(time(0));

  while (contador < numeroMinas)
  {
    for (linha = 0; linha < tamTabuleiro && contador < numeroMinas; linha++)
    {
      for (coluna = 0; coluna < tamTabuleiro; coluna++)
      {
        const int random = rand() % 101;

        if (contador > numeroMinas)
        {
          break;
        }

        if (random <= (100*numeroMinas/(tamTabuleiro*tamTabuleiro)) && contador < numeroMinas)
        {
          Jogo.tabuleiro.jogavel[linha][coluna] = BOMBA;
          contador++;
        }
      }
    }
  }
}