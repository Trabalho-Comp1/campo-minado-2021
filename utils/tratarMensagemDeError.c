void tratarMensagemDeError(char mensagem[50])
{
  printf("\033[0;31m"); /* Muda para vermelho */
  puts(mensagem);
  printf("\033[0m"); /* Volta para a cor padrão */
  puts("Pressione qualquer tecla para continuar");
  getchar();
  getchar();
}