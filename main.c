#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  int dificuldadeEscolhida;
  char GAME_STATE = PLAYING;

  TABULEIRO tabuleiro;

  introducao();

  scanf("%i", &dificuldadeEscolhida);
  do{}while(getchar()!='\n');

  if (dificuldadeEscolhida == FACIL)
  {
    tabuleiro.dificuldade = facil;
  }
  else if (dificuldadeEscolhida == MEDIO)
  {
    tabuleiro.dificuldade = medio;
  }
  else if (dificuldadeEscolhida == DIFICIL)
  {
    tabuleiro.dificuldade = dificil;
  }
  else
  {
    exit(0);
  }

  tabuleiro = criarTabuleiro(tabuleiro.dificuldade);
  sortearMinas(tabuleiro);
  verificarCasasAdjacentes(tabuleiro);
  
  /* GAME LOOP */
  while (GAME_STATE == PLAYING)
  {
    int linha = 0, coluna = 0, *elemento, *elementoEspelho;
    char operacao=' ';

    draw(tabuleiro);
    puts("==============================");
    puts("Digite a linha e a coluna desejadas e um M no final caso queira marcar/desmarcar aquela casa. Ex: '0 3' ou '0 3 M'.");
    scanf("%i %i", &linha, &coluna);
    operacao = getchar();

    if ((linha < 0 || coluna < 0) ||                       /* menor do que o tabuleiro */
        (linha >= tabuleiro.dificuldade.tam || coluna >= tabuleiro.dificuldade.tam)) /* maior do que o tabuleiro */
    {
      tratarMensagemDeError("Casa nao existente");
      continue;
    }

    elemento = &tabuleiro.jogavel[linha][coluna];
    elementoEspelho = &tabuleiro.espelho[linha][coluna];

    if(*elementoEspelho == 1){
      tratarMensagemDeError("Casa ja selecionada!");
      continue;
    }

    if((operacao=='M' || operacao=='m') && *elementoEspelho!=CASA_ABERTA){
      if(*elementoEspelho==CASA_FECHADA){
        *elementoEspelho = CASA_MARCADA;
      }else{
       *elementoEspelho = CASA_FECHADA;
      }
      continue;
    } else{
      if (*elemento == BOMBA)
      {
        popularMatrizCom(1, tabuleiro.espelho, tabuleiro.dificuldade.tam);
        draw(tabuleiro);
        printf("\033[0;31m");
        puts("Kaboooom ! Voce acertou uma bomba ! Game Over");
        printf("\033[0m");
        GAME_STATE = GAME_OVER;
      }
      else{
        *elementoEspelho = 1;
        tabuleiro.casasAbertas++;

        if(*elemento==0){
          revelarCasas(&tabuleiro, linha, coluna);  
        }
        
        /* Caso todas as casas forem abertas, menos as que contém bombas => vitória */
        if(tabuleiro.casasAbertas == tabuleiro.dificuldade.tam*tabuleiro.dificuldade.tam - tabuleiro.dificuldade.nMinas){
            draw(tabuleiro);
            printf("\033[0;32m");
            puts("Parabens! Voce ganhou o jogo!");
            printf("\033[0m");
            GAME_STATE = GAME_OVER;
        }
      }
    }
  }

  return 0;
}