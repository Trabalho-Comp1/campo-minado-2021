#include "main.h"

extern DIFICULDADE Facil, Medio, Dificil;

int main()
{
  int dificuldadeEscolhida;

  /* Função para mostrar a tela inicial do jogo */
  introducao();
  
  /* Escolhendo e setando dificuldade do jogo */
  scanf("%i", &dificuldadeEscolhida);
  do{} while (getchar() != '\n');

  if (dificuldadeEscolhida == FACIL)
  {
    Jogo.dificuldade = Facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    Jogo.dificuldade = Medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    Jogo.dificuldade = Dificil;
  }
  else
  {
    exit(0);
  }

  /* Iniciando o jogo */
  Jogo.tabuleiro = criarTabuleiro();
  sortearMinas();
  verificarCasasAdjacentes();
  Jogo.GAME_STATE = PLAYING;

  /* GAME LOOP */
  while (Jogo.GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, *elemento, *elementoEspelho;
    char operacao = ' ';

    draw();
    puts("Digite a linha e a coluna desejadas. Ex: '0 3'.");
    printf("Caso queira marcar/desmarcar a casa, digite um M depois da coluna. Ex: '0 3M'.\n");
    scanf("%i %i%c", &linha, &coluna, &operacao);

    /* Verificar se casa escolhida existe */
    if ((linha < 0 || coluna < 0) ||                                       /* menor do que o tabuleiro */
        (linha >= Jogo.dificuldade.tam || coluna >= Jogo.dificuldade.tam)) /* maior do que o tabuleiro */
    {
      tratarMensagemDeError("Casa nao existente!");
      continue;
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
      continue;
    }

    if (*elementoEspelho == CASA_ABERTA)
    {
      tratarMensagemDeError("Casa ja selecionada!");
      continue;
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

      continue;
    }
    else if (*elemento == BOMBA)
    {
      popularMatrizCom(1, Jogo.tabuleiro.espelho);
      draw();
      printf("\033[0;31m");
      puts("Kaboooom! Voce acertou uma bomba! Game Over.");
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
      puts("Parabens! Voce ganhou o jogo!");
      printf("\033[0m");
      Jogo.GAME_STATE = GAME_OVER;
    }

    Jogo.numJogadas++;
  }

  return 0;
}