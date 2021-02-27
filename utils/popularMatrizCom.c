void popularMatrizCom(int valor, int **matriz)
{
  int linha, coluna;
  for (linha = 0; linha < Jogo.dificuldade.tam; linha++)
  {
    for (coluna = 0; coluna < Jogo.dificuldade.tam; coluna++)
    {
      matriz[linha][coluna] = valor;
    }
  }
}