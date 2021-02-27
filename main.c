#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  /* TABULEIRO *tabuleiro; */
  int dificuldadeEscolhida;
  /* char GAME_STATE = PLAYING; */
  setlocale(LC_ALL, "Portuguese");
  fwide(stdout, 1);
  /* fputwc(L'\uFEFF', stdout); */

  introducao();
  scanf("%i", &dificuldadeEscolhida);

  do
  {
  } while (getchar() != '\n');

  if (dificuldadeEscolhida == FACIL)
  {
    /* tabuleiro.dificuldade = facil; */
    Jogo.dificuldade = facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    /* tabuleiro.dificuldade = medio; */
    Jogo.dificuldade = medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    /* tabuleiro.dificuldade = dificil; */
    Jogo.dificuldade = dificil;
  }
  else
  {
    exit(0);
  }

  Jogo.tabuleiro = criarTabuleiro();
  sortearMinas();
  verificarCasasAdjacentes();
  Jogo.GAME_STATE = PLAYING;

  /* GAME LOOP */
  while (Jogo.GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, elemento, elementoEspelho;
    char operacao = ' ';

    draw();
    puts("Digite a linha e a coluna desejadas. Ex: '0 3'.");
    printf("Caso queira marcar/desmarcar a casa, digite um M após a coluna. Ex: '0 3M'.\n");
    scanf("%i %i", &linha, &coluna);
    /* operacao = getchar(); */

    if ((linha < 0 || coluna < 0) ||                                       /* menor do que o tabuleiro */
        (linha >= Jogo.dificuldade.tam || coluna >= Jogo.dificuldade.tam)) /* maior do que o tabuleiro */
    {
      tratarMensagemDeError("Casa não existente!");
      continue;
    }

    elemento = Jogo.tabuleiro.jogavel[linha][coluna];
    elementoEspelho = Jogo.tabuleiro.espelho[linha][coluna];

    if (Jogo.numJogadas == 0 && elemento == BOMBA)
    {
      reposicionarMina(linha, coluna);
      verificarCasasAdjacentes();

      elementoEspelho = CASA_ABERTA;
      Jogo.casasAbertas++;
      revelarCasas(linha, coluna);

      continue;
    }

    if (elementoEspelho == CASA_ABERTA)
    {
      tratarMensagemDeError("Casa já selecionada!");
      continue;
    }

    if ((operacao == 'M' || operacao == 'm') && elementoEspelho != CASA_ABERTA)
    {
      if (elementoEspelho == CASA_FECHADA)
      {
        elementoEspelho = CASA_MARCADA;
      }
      else
      {
        elementoEspelho = CASA_FECHADA;
      }
      
      continue;
    }
    else if (elemento == BOMBA)
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
      elementoEspelho = CASA_ABERTA;
      Jogo.casasAbertas++;

      if (elemento == 0)
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

  return 0;
}