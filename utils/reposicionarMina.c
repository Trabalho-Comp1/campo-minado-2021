void reposicionarMina(int linha, int coluna)
{
  unsigned int i, j;
  for (i = 0; i < Jogo.dificuldade.tam; i++)
  {
    for (j = 0; j < Jogo.dificuldade.tam; j++)
    {
      /* Posiciona a mina na primeira casa sem mina */
      if(Jogo.tabuleiro.jogavel[i][j] != BOMBA)
      {
        /* tabuleiro.jogavel[i][j] = tabuleiro.jogavel[linha][coluna]; */
        Jogo.tabuleiro.jogavel[i][j] = BOMBA;
        Jogo.tabuleiro.jogavel[linha][coluna] = SEM_BOMBA;
        return;
      }
    }
    
  }
  
}