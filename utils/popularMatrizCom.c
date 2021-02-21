void popularMatrizCom(int valor, int **matriz, int tamMatriz)
{
  int linha, coluna;
  for (linha = 0; linha < tamMatriz; linha++)
  {
    for (coluna = 0; coluna < tamMatriz; coluna++)
    {
      matriz[linha][coluna] = valor;
    }
  }
}