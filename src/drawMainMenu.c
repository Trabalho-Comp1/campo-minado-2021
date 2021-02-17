#include "drawMainMenu.h"

void drawMainMenu(void)
{
  char opcoes[4][16] = {
      "Facil",
      "Medio",
      "Dificil",
      "Sair"};

  int selecao = 0;

  while (dificuldadeEscolhida != 3)
  {
    int i, op;

    /* clrscr(); */
    system("cls");
    /* system("clear"); */

    puts("====== JOGO DO CAMPO DO MINADO ======");
    puts("Desenvolvido por: Abid Lohan, Diego Matos e Lia Barcellos");
    puts("=======================================");
    puts("Escolha a dificuldade do jogo:");

    for (i = 0; i < 4; i++)
    {
      const char *opcao = opcoes[i];
      if (selecao == i)
      {
        printf("\033[30;47m");
      }
      printf("\t%s\n", opcao);
      printf("\033[0m");
    }

    op = getch();

    if (op == 13)
    {
      switch (getch())
      {
        case '\r':
          dificuldadeEscolhida = selecao;
          break;
      }
    }

    if (op == 0 || op == 224)
    {
      switch (getch())
      {
      case 72:
        /* Down Up Handling */
        if (selecao == 0)
        {
          selecao = 3;
        }
        else
        {
          selecao--;
        }
        break;

      case 80:
        /* Down Arrow Handling */
        if (selecao == 3)
        {
          selecao = 0;
        }
        else
        {
          selecao++;
        }

        break;

      case '\r':
        dificuldadeEscolhida = selecao;
      }
    }

    /* dificuldadeEscolhida = op; */
  }
}