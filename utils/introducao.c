void introducao(){
    printf("\033[1;1H\033[2J"); /*Limpar terminal (teoricamente funciona Linux/Win)*/
    puts("\n==== JOGO DO CAMPO DO MINADO ====\n");

    puts("     ,--.!,\n"
         "  __/   -*-\n"
         ",d08b.  '|`\n"
         "0088MM\n"
         "`9MMP'\n");

    puts("Desenvolvido por: Abid Lohan, Diego Matos e Lia Barcellos\n");
    puts("=====================================================================\n");

    puts("Escolha a dificuldade do jogo:");
    puts("[1] - Facil, [2] - Medio, [3] - Dificil, [4] - SAIR");
}