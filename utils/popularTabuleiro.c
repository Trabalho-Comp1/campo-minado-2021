void popularTabuleiro(TABULEIRO tabuleiro)
{
  popularMatrizCom(0, tabuleiro.jogavel, tabuleiro.dificuldade.tam);
  popularMatrizCom(0, tabuleiro.espelho, tabuleiro.dificuldade.tam);
}