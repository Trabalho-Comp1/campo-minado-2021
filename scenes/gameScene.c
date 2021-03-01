#include "gameScene.h"

void renderGameScene(void)
{
  int linha = 0, coluna = 0, *elemento, *elementoEspelho;
  char operacao = ' ';

  desenharTabuleiro();
  puts("Digite a linha e a coluna desejadas. Ex: '0 3'.");
  wprintf(L"Caso queira marcar/desmarcar a casa, digite um M após a coluna. Ex: '0 3M'.\n");
  scanf("%i %i%c", &linha, &coluna, &operacao);

  /* Verificar se casa escolhida existe */
  if ((linha < 0 || coluna < 0) ||                                       /* menor do que o tabuleiro */
      (linha >= Jogo.dificuldade.tam || coluna >= Jogo.dificuldade.tam)) /* maior do que o tabuleiro */
  {
    tratarMensagemDeError("Casa nao existente!");
    /* continue; */
    return;
  }

  elemento = &Jogo.tabuleiro.jogavel[linha][coluna];
  elementoEspelho = &Jogo.tabuleiro.espelho[linha][coluna];

  /* Primeira casa não pode ser bomba */
  if (Jogo.numJogadas == 0 && *elemento == BOMBA)
  {
    reposicionarMina(linha, coluna);
    verificarCasasAdjacentes();

    *elementoEspelho = CASA_ABERTA;
    Jogo.casasAbertas++;
    revelarCasas(linha, coluna);
    /* continue; */
    return;
  }

  if (*elementoEspelho == CASA_ABERTA)
  {
    tratarMensagemDeError("Casa ja selecionada!");
    /* continue; */
    return;
  }

  /* Jogador pode marcar uma casa */
  if ((operacao == 'M' || operacao == 'm') && *elementoEspelho != CASA_ABERTA)
  {
    if (*elementoEspelho == CASA_FECHADA)
    {
      *elementoEspelho = CASA_MARCADA;
    }
    else
    {
      *elementoEspelho = CASA_FECHADA;
    }

    /* continue; */
    return;
  }
  else if (*elemento == BOMBA)
  {
    popularMatrizCom(1, Jogo.tabuleiro.espelho);
    draw();
    printf("\033[0;31m");
    wprintf(L"Kaboooom! Você acertou uma bomba! Game Over.\n");
    printf("\033[0m");
    Jogo.GAME_STATE = GAME_OVER;
  }
  else
  {
    *elementoEspelho = CASA_ABERTA;
    Jogo.casasAbertas++;

    if (*elemento == 0)
    {
      revelarCasas(linha, coluna);
    }
  }

  /* Caso todas as casas forem abertas, menos as que contém bombas => vitória */
  if (Jogo.casasAbertas == Jogo.dificuldade.tam * Jogo.dificuldade.tam - Jogo.dificuldade.nMinas)
  {
    draw();
    printf("\033[0;32m");
    wprintf(L"Parabéns! Você ganhou o jogo!\n");
    printf("\033[0m");
    Jogo.GAME_STATE = GAME_OVER;
  }

  Jogo.numJogadas++;
}