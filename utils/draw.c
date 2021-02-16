void draw(int **tabuleiro, int tamTabuleiro, int **tabuleiroEspelho)
{
  int linha, coluna;
  system("cls");
  for (int linha = -1; linha < tamTabuleiro; linha++)
  system("clear");
  for (linha = 0; linha < tamTabuleiro; linha++)
  {
    if (linha == -1)
    {
      printf("\t");
    }
    else
    {
      printf("%i\t", linha);
    }

    for (coluna = 0; coluna < tamTabuleiro; coluna++)
    {
      if (linha == -1)
      {
        printf(" %i\t", coluna);
        continue;
      }

      if (tabuleiroEspelho[linha][coluna] == 0)
      {
        /* printf("[%i, %i]\t", linha, coluna); */
        printf("[X]\t");
      }
      else
      {
        /* printf("[  %i  ]\t", tabuleiro[linha][coluna]); */
        printf("[%i]\t", tabuleiro[linha][coluna]);
      }
    }
    printf("\n");
  }
}

/*  
  for(i=0;i<FILEIRAS+1;i++) {
    for(j=0;j<COLUNAS+1;j++) {
      if(i==0) {
        if(j==0) {
          printf("\t");
          continue;  
        } else {
          printf("%c\t", j-1+'A');
          continue;
        }
      }
      if(j==0) {
        printf("%02d\t", i);
        continue;
      }
      printf("%c\t", poltronas[i][j]);
    }
    printf("\n");
  }
*/