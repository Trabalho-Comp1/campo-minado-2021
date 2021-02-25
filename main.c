#include "main.h"

extern DIFICULDADE facil, medio, dificil;

int main()
{
  int dificuldadeEscolhida;
  char GAME_STATE = PLAYING;

  TABULEIRO tabuleiro;

  introducao();

  scanf("%i", &dificuldadeEscolhida);
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
    int linha = 0, coluna = 0, elemento;

    draw(tabuleiro);
    puts("Digite a linha e coluna desejadas separadas por um espaço. Ex: '0 3'.");
    scanf("%i %i", &linha, &coluna);

    if ((linha < 0 || coluna < 0) ||                       /* menor do que o tabuleiro */
        (linha >= tabuleiro.dificuldade.tam || coluna >= tabuleiro.dificuldade.tam)) /* maior do que o tabuleiro */
    {
      tratarMensagemDeError("Casa nao existente");
      continue;
    }

    elemento = tabuleiro.jogavel[linha][coluna];

    if (elemento == BOMBA)
    {
      popularMatrizCom(1, tabuleiro.espelho, tabuleiro.dificuldade.tam);
      draw(tabuleiro);
      printf("\033[0;31m");
      puts("Kaboooom ! Voce acertou uma bomba ! Game Over");
      printf("\033[0m");
      GAME_STATE = GAME_OVER;
    }
    else{
      tabuleiro.espelho[linha][coluna] = 1;
      tabuleiro.casasAbertas++;

      if(elemento==0){
        revelarCasas(&tabuleiro, linha, coluna);  
      }
      
      /* Caso todas as casas forem abertas, menos as que conterem bombas => vitória */
      if(tabuleiro.casasAbertas == tabuleiro.dificuldade.tam*tabuleiro.dificuldade.tam - tabuleiro.dificuldade.nMinas){
          draw(tabuleiro);
          puts("Parabens! Voce ganhou o jogo!");
          GAME_STATE = GAME_OVER;
      }
    }
  }

  return 0;
}